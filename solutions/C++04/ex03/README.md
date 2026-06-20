# C++04 ex03 — Interfaces, Abstract Classes & Design Patterns

## Що тут вчать

Це фінальна вправа модуля 04. Вона збирає **все разом**:
- поліморфізм (`virtual`)
- абстрактні класи (`= 0`)
- «інтерфейси» (pure abstract class)
- патерн **Prototype** (клонування)
- патерн **Factory** (фабрика об'єктів)
- керування динамічною пам'яттю
- Rule of Three (OCF) на реальному прикладі

---

## 1. Інтерфейс у C++98

### Що таке інтерфейс?

В інших мовах (Java, C#) є спеціальне слово `interface`. У C++98 його немає. Замість цього **інтерфейс = pure abstract class** — клас, де:

- **всі** публічні методи є `= 0` (pure virtual)
- немає полів даних (тільки методи)
- **неможливо** створити об'єкт цього класу напряму

```cpp
// Це інтерфейс — лише контракт, нуль реалізації
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};
```

```cpp
ICharacter obj;        // ❌ compile error — pure virtual methods
ICharacter *p = new Character("me");  // ✅ pointer to interface is fine
```

### Навіщо це потрібно?

Без інтерфейсу код знає конкретний тип (`Character`). З інтерфейсом код знає лише контракт (`ICharacter`) — і може працювати з **будь-яким** класом, що його реалізує.

```cpp
void fight(ICharacter &attacker, ICharacter &target) {
    attacker.use(0, target);  // не знає, що attacker — це Character
}
```

Це **поліморфізм на рівні інтерфейсу**.

---

## 2. Абстрактний клас vs Інтерфейс

| | Абстрактний клас | Інтерфейс |
|---|---|---|
| **Поля** | може мати | зазвичай немає |
| **Реалізовані методи** | може мати | немає (всі `= 0`) |
| **Приклад** | `AMateria` (має `_type`) | `ICharacter`, `IMateriaSource` |
| **Мета** | спільна база + частина логіки | чистий контракт |

`AMateria` — **абстрактний клас**: має поле `_type` і реалізований `getType()`, але `clone()` — pure virtual.

`ICharacter` — **інтерфейс**: нуль даних, нуль реалізацій, всі методи `= 0`.

---

## 3. `= 0` — що це означає

```cpp
virtual AMateria *clone() const = 0;
```

`= 0` означає:
1. Метод **не має реалізації** у цьому класі
2. Кожен похідний клас **зобов'язаний** перевизначити його
3. Клас, що містить хоч один `= 0`, стає **абстрактним** — його не можна інстанціювати

```cpp
class AMateria {
    virtual AMateria *clone() const = 0;  // pure virtual
};

class Ice : public AMateria {
    AMateria *clone() const { return new Ice(*this); }  // обов'язково!
};

AMateria *a = new AMateria();  // ❌ error: cannot instantiate abstract class
AMateria *b = new Ice();       // ✅
```

---

## 4. Патерн Prototype (клонування)

### Проблема

Коли ми маємо вказівник `AMateria *`, ми не знаємо точного типу — `Ice` чи `Cure`. Як скопіювати об'єкт правильного типу?

```cpp
AMateria *original = getMateria();  // Ice або Cure — не знаємо
AMateria *copy = ???;               // як зробити копію?
```

### Рішення: Prototype

Кожен клас сам знає, як себе скопіювати:

```cpp
// Кожен конкретний клас реалізує clone()
AMateria *Ice::clone() const  { return new Ice(*this); }
AMateria *Cure::clone() const { return new Cure(*this); }

// Тепер через вказівник на базу отримуємо правильний тип
AMateria *original = new Ice();
AMateria *copy = original->clone();  // викличеться Ice::clone() → new Ice
```

### Як це відрізняється від copy constructor

| | Copy constructor | `clone()` |
|---|---|---|
| **Виклик** | `Ice a(b)` — знаємо тип | `ptr->clone()` — не знаємо тип |
| **Через базовий вказівник** | ❌ неможливо | ✅ так |
| **Де використовується** | `Ice(Ice const &)` | `MateriaSource`, `Character` deep copy |

---

## 5. Патерн Factory (фабрика)

### Проблема

Як створити об'єкт за рядком типу, не знаючи точного класу на етапі компіляції?

```cpp
std::string type = "ice";
// Як отримати new Ice() ?
```

### Рішення: Factory

`MateriaSource` зберігає шаблони і клонує їх за запитом:

```cpp
src->learnMateria(new Ice());    // зберігає шаблон
src->learnMateria(new Cure());

AMateria *m = src->createMateria("ice");  // повертає new Ice — клон шаблону
```

Всередині `createMateria`:
```cpp
for (int i = 0; i < 4; i++) {
    if (_templates[i] && _templates[i]->getType() == type)
        return _templates[i]->clone();  // Prototype + Factory разом
}
return 0;  // невідомий тип
```

### Різниця між learnMateria і createMateria

| | `learnMateria(m)` | `createMateria("ice")` |
|---|---|---|
| **Що робить** | клонує m → зберігає шаблон, `delete m` | знаходить шаблон → повертає клон |
| **Власність** | бере ownership від caller | повертає ownership caller |
| **Виклики clone()** | 1 раз (при збереженні) | 1 раз (при поверненні) |

---

## 6. Virtual dispatch (динамічне зв'язування)

Коли через вказівник `AMateria *` або `ICharacter *` викликається метод — C++ вирішує **під час виконання** (runtime), яку версію методу викликати:

```cpp
AMateria *m = new Ice();
m->use(*target);  // викликається Ice::use(), а не AMateria::use()
```

Це відбувається через **vtable** — таблицю вказівників на методи, яку C++ будує для кожного класу з `virtual`.

```
AMateria vtable:  use → AMateria::use
Ice vtable:       use → Ice::use       ← override
Cure vtable:      use → Cure::use      ← override
```

Саме тому `clone() = 0` і `virtual ~AMateria()` — обов'язкові.

---

## 7. Rule of Three в контексті ex03

Щоразу, коли клас **керує ресурсом** (heap пам'ять через `new`), потрібні всі три:

```
Destructor + Copy Constructor + Copy Assignment Operator
```

### Character (керує _inventory[4])

```cpp
// 1. Destructor — звільнити матерії
~Character() { for (int i = 0; i < 4; i++) delete _inventory[i]; }

// 2. Copy constructor — клонувати матерії
Character(const Character &other) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : 0;
}

// 3. Copy assignment — спочатку delete старих, потім clone нових
Character &operator=(const Character &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) { delete _inventory[i]; _inventory[i] = 0; }
        for (int i = 0; i < 4; i++)
            if (other._inventory[i]) _inventory[i] = other._inventory[i]->clone();
    }
    return *this;
}
```

### MateriaSource (керує _templates[4])

Та сама структура: destructor, copy constructor, copy assignment — всі через `clone()`.

---

## 8. Ownership — хто відповідає за delete

**Ownership** = відповідальність за `delete` об'єкта в heap.

| Дія | Хто стає власником |
|---|---|
| `new Ice()` | той, хто викликав `new` |
| `learnMateria(new Ice())` | MateriaSource (він `clone()` і `delete` оригінал) |
| `createMateria("ice")` | caller (повернутий клон — його відповідальність) |
| `equip(m)` | Character (тепер він відповідає за цю materia) |
| `unequip(idx)` | відповідальність повертається до caller |
| `~Character()` | Character `delete` те, що ще в інвентарі |

### Типова помилка: leak після unequip

```cpp
character->unequip(0);  // слот = NULL, але materia в heap!
// Якщо не зберегти вказівник і не delete — leak
```

**Правильно:**
```cpp
AMateria *saved = character->getInventory(0);  // зберегти
character->unequip(0);
// ... зробити щось із saved ...
delete saved;  // звільнити
```

---

## 9. Forward declaration vs include

У `ICharacter.hpp` є:
```cpp
class AMateria;  // forward declaration
```

а не:
```cpp
#include "AMateria.hpp"  // повний include
```

**Навіщо?** `ICharacter` лише використовує `AMateria *` — вказівник. Для вказівника не потрібно знати повний клас, лише що він існує. Це розриває **циклічну залежність**:

```
AMateria.hpp включає ICharacter.hpp
ICharacter.hpp включає AMateria.hpp  ← loop!
```

Forward declaration вирішує це без циклу.

---

## 10. Структура класів і залежності

```
IMateriaSource (interface)          ICharacter (interface)
      │                                    │
      │ implements                         │ implements
      ▼                                    ▼
MateriaSource                         Character
  _templates[4]: AMateria*           _inventory[4]: AMateria*
  learnMateria() → clone + store      equip()   → store ptr
  createMateria() → clone + return    unequip() → set NULL
                                       use()     → delegate to AMateria

AMateria (abstract base)
  _type: string
  clone() = 0   ← Prototype pattern
  use()         ← overridden in subclasses
      │
      ├── Ice   (type="ice",  use → ice bolt message)
      └── Cure  (type="cure", use → heal message)
```

---

## 11. Повний flow subject main крок за кроком

```cpp
IMateriaSource *src = new MateriaSource();
```
- Створено MateriaSource, всі 4 слоти шаблонів = NULL

```cpp
src->learnMateria(new Ice());
```
- Створено Ice (тимчасовий)
- learnMateria: `_templates[0] = ice->clone()` → новий Ice у слоті 0
- `delete` тимчасовий Ice

```cpp
src->learnMateria(new Cure());
```
- Аналогічно: `_templates[1]` = новий Cure

```cpp
ICharacter *me = new Character("me");
```
- Створено Character "me", всі 4 інвентарні слоти = NULL

```cpp
tmp = src->createMateria("ice");
me->equip(tmp);
```
- `createMateria`: знайдено `_templates[0]` (тип "ice") → повернуто `_templates[0]->clone()` — новий Ice
- `equip`: `_inventory[0] = tmp`

```cpp
tmp = src->createMateria("cure");
me->equip(tmp);
```
- Аналогічно: `_inventory[1]` = новий Cure

```cpp
me->use(0, *bob);
```
- `_inventory[0]->use(*bob)` → `Ice::use(*bob)`
- virtual dispatch: виконується `Ice::use`
- Вивід: `* shoots an ice bolt at bob *`

```cpp
me->use(1, *bob);
```
- `_inventory[1]->use(*bob)` → `Cure::use(*bob)`
- Вивід: `* heals bob's wounds *`

```cpp
delete bob; delete me; delete src;
```
- `~Character("bob")` → `delete _inventory[0..3]` (всі NULL — нічого)
- `~Character("me")` → `delete _inventory[0]` (Ice), `delete _inventory[1]` (Cure)
- `~MateriaSource` → `delete _templates[0]` (Ice), `delete _templates[1]` (Cure)

---

## 12. Зв'язок усіх вправ модуля 04

| Вправа | Концепція | Що нового |
|---|---|---|
| **ex00** | `virtual makeSound()` | поліморфізм — правильний метод через базовий вказівник |
| **ex01** | `Brain *_brain` | динамічна пам'ять у класі, deep copy, Rule of Three |
| **ex02** | `= 0` в `AAnimal` | abstract class — базовий клас не можна інстанціювати |
| **ex03** | Interfaces + Prototype + Factory | чисті інтерфейси, клонування, фабрика, повне управління пам'яттю |

---

## 13. Ключові правила щодо пам'яті

| Ситуація | Правило |
|---|---|
| `learnMateria(new Ice())` | MateriaSource клонує і `delete` оригінал |
| `createMateria("ice")` | повертає клон — **caller** робить `delete` |
| `equip(m)` | Character стає власником m |
| `unequip(idx)` | **не** `delete`, лише `= NULL` — caller знову власник |
| `~Character()` | `delete` всього в інвентарі |
| `~MateriaSource()` | `delete` всіх шаблонів |
| Copy constructor/operator= | спочатку `delete` старого, потім `clone()` нового |

---

## 14. Тести у main.cpp

| Тест | Що перевіряє |
|---|---|
| **1** | Subject main — точний вивід `ice bolt` + `heals` |
| **2** | Повний інвентар (4/4) — 5-й `equip` тихо ігнорується |
| **3** | `unequip(0)` → слот NULL → `use(0)` нічого не робить |
| **4** | Deep copy `Character` — materia у c1 і c2 незалежні |
| **5** | `createMateria("fire")` → невідомий тип → повертає `0` |
