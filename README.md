*This project has been created as part of the 42 curriculum by olcherno*

# NetPractice

## Description

NetPractice is an interactive networking training project designed to teach and test practical network configuration and troubleshooting skills through a series of incremental levels. Each level presents a small lab focused on real-world concepts (addressing, subnetting, routing, switching, services) and requires the student to build, configure, and validate network setups.

## Instructions

- Run the training interface from the repository root (if provided) using:

```bash
./run.sh
```

- To run a specific level (if the interface supports it):

```bash
./run.sh level<N>
```

- Exporting configurations: use the provided export tool or interface. Example (if present):

```bash
./export_configs.sh level<N> > level<N>.cfg
```

- Submission requirements:
  - Export and place **10** configuration files (one per level) at the repository root. Files should be named clearly, e.g. `level1.cfg`, `level2.cfg`, … `level10.cfg`.
  - Include any notes or validation steps you used to verify each level in a short text file alongside the exports.

## Resources

Classic references and study material:

- TCP/IP addressing and subnetting (CIDR notation, subnet masks)
- Default gateways and host routing
- Routers and switches: basic configuration and forwarding behavior
- OSI and TCP/IP model layers and their roles
- NAT, DHCP, ARP, and DNS fundamentals
- Routing concepts and protocols (static routing, RIP, OSPF basics)

Useful links and docs:

- RFCs and vendor documentation (Cisco, Juniper, etc.)
- Online tutorials and subnet calculators
- Network simulation/emulation tools (GNS3, Packet Tracer, Netkit)


## Networking concepts studied

This project explicitly practices and reinforces the following networking concepts:

- TCP/IP addressing and subnet masks
- Default gateways and routing basics
- Routers and switches behaviour and configuration
- OSI layers and how protocols map to layers
- ARP, DHCP and DNS interactions
- NAT and port forwarding concepts

## Submission checklist

- Place 10 exported configuration files at the repository root: `level1.cfg` … `level10.cfg`.
- Add a short `validation.txt` describing how you verified each level (commands used, tests performed).
- Ensure README.md is present and up to date.

## Project structure (recommended)

- `levels/` — source files, lab configs, and scripts for each level
- `run.sh` — main runner for the training interface (optional)
- `export_configs.sh` — helper to export configs (optional)
- `level<N>.cfg` — exported configuration files for submission


