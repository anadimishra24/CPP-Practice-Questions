# SONiC



- Stands for **S**oftware for **O**pen **N**etworking **i**n the **C**loud

- Based on Linux operating system.

- Developed by Microsoft and Open Compute Project , then open sourced in 2016.



## Things to know about other than just SONiC

>

> :memo: [Docker](#docker)

>

> :memo: [Azure](#azure)

>

> :memo: [APIs](#apis)



## Topics to be covered



### Links

>

> [SONiC](https://github.com/sonic-net/SONiC/wiki)

>

> [Architecture and Sub-Architecture](https://github.com/sonic-net/SONiC/wiki/Architecture)



### Topics

>

> Introduction to SONiC



```text

    - Overview of SONiC as an open-source network operating system.

    - Key goals and benefits of using SONiC in cloud-scale networking environments.

```



> SONiC Architecture:



```text

    - Understanding the modular architecture of SONiC.

    - Overview of different components and their functionalities.

```



> Hardware Compatibility:



```text

    - Exploring the range of network hardware platforms compatible with SONiC.

    - Benefits of leveraging existing infrastructure with SONiC.

```



> Programmability and Automation in SONiC:



```text

    - Understanding the API-driven approach of SONiC for configuration and management.

    - Integration with popular automation frameworks like Ansible and Puppet.

```



> Networking Features in SONiC:



```text

    - Overview of essential networking features supported by SONiC.

    - Layer 2 switching, Layer 3 routing, virtualization, QoS, telemetry, security, and monitoring capabilities.

```



> Industry Adoption and Use Cases:



```text

    - Examining real-world examples of organizations deploying SONiC.

    - Understanding how cloud providers, enterprises, and service providers benefit from using SONiC.

```



## Key Points About SONiC



Here are some key points about SONiC:



1. Open Source: SONiC is an open-source project that encourages collaboration and contributions from the networking community. It is hosted and maintained by the OCP.



2. Cloud Networking: SONiC is specifically designed for cloud-scale networking environments, where flexibility, scalability, and automation are crucial.



3. Hardware Compatibility: SONiC can run on a variety of network hardware platforms, including switches from different vendors, enabling organizations to leverage their existing infrastructure.



4. Modular Architecture: SONiC follows a modular architecture that allows for independent development and deployment of various components, such as routing protocols, switch ASIC drivers, and monitoring applications.



5. Programmability and Automation: SONiC provides an API-driven approach, allowing network operators to automate configuration, management, and monitoring tasks. It supports popular automation frameworks like Ansible and Puppet.



6. Industry Adoption: SONiC has gained significant industry adoption and has been deployed by major cloud providers, enterprises, and service providers. It has a growing ecosystem of vendors, developers, and users contributing to its development and interoperability.



7. Features: SONiC supports a range of networking features, including Layer 2 switching, Layer 3 routing, virtualization, Quality of Service (QoS), telemetry, security, and network monitoring.



8. Community and Support: SONiC benefits from an active community of users and contributors who provide support, share best practices, and contribute to its ongoing development and enhancement.



## What are switches ?



```text

Switches are devices used in computer networking to connect devices together and allow them to communicate with each other. They operate at the data link layer of the OSI model and are responsible for forwarding data packets between devices on a network. Switches can be managed or unmanaged, and they come in different sizes and configurations depending on the needs of the network.

Switches run on network operating systems (NOSs), which are specialized operating systems designed for network devices such as routers, switches, and firewalls.

NOSs can be proprietary or open source, and they are responsible for managing the hardware resources of the switch, as well as providing features such as VLANs, QoS, and security.



Here are some examples of NOSs that switches can run on:

    Stratum Project

    Cumulus Networks

    Big Switch Switch Light

    Open Network Linux

    Dent – Linux Foundation

    PICA8

    Dell Systems





+-----------------+       +-----------------+       +-----------------+

|                 |       |                 |       |                 |

|   End Devices   |       |   End Devices   |       |   End Devices   |

|                 |       |                 |       |                 |

+-----------------+       +-----------------+       +-----------------+

         |                       |                       |

         |                       |                       |

         |                       |                       |

+-----------------+       +-----------------+       +-----------------+

|                 |       |                 |       |                 |

|     Switch 1    |-------|     Router 1    |-------|     Switch 2    |

|                 |       |                 |       |                 |

+-----------------+       +-----------------+       +-----------------+

         |                                                       |

         |                                                       |

         |                                                       |

+-----------------+                                       +-----------------+

|                 |                                       |                 |

|     Switch 3    |---------------------------------------|     Router 2    |

|                 |                                       |                 |

+-----------------+                                       +-----------------+

         |                                                       |

         |                                                       |

         |                                                       |

+-----------------+                                       +-----------------+

|                 |                                       |                 |

|   End Devices   |                                       |   End Devices   |

|                 |                                       |                 |

+-----------------+                                       +-----------------+



In this diagram, there are multiple switches and routers connected to each other. End devices such as computers, printers, and servers are connected to the switches. The switches are responsible for forwarding data packets between devices on the network. The routers connect different networks together, and they use routing protocols to determine the best path for data to travel.



```



## Platform Support



The platforms that support SONiC are:



```text

    Arista Networks: 7050 and 7060 series

    Centec Networks: E580 and E582 series

    Dell Inc: S6000 ON, S6100-ON and Z9100-ON series

    Edge-core Networks: AS7512 series, Wedge-100b

    Facebook: Wedge-100

    Ingrasys Technology Inc.: S9100 series

    Marvell Technology Group Ltd.: RD-BC3-4825G6CG-A4 and RD-ARM-48XG6CG-A4 series

    Mellanox Technologies: SN2700 series

    With SONiC, the cloud community has choices—they can cherry pick best-of-breed solutions. 

```



Partners are joining the eco-system to make it richer:



```text

    Arista is offering containerized EOS components like EOS BGP to run on top of SONiC. The SONiC community now has easy access to Arista’s rich software suite of EOS.

    Canonical enabled SONiC as a snap for Ubuntu. It enables MAAS to deploy SONiC to switches as well as using SONiC to deploy the servers. Unified network and server deployment is going to significantly improve the agility of operators.

    Docker enabled using Swarm to manage the SONiC containers. With its simple and declarative service model, Swarm can manage and update SONiC at scale.

    Mellanox is using SONiC to unleash the hardware-based packet generation capabilities in the Spectrum ASIC. This is a highly sought-after capability that will help diagnosis and troubleshooting.

```



### SONiC System Architecture



[Need to learn about Monolithic Architecture Microservices Architecture] (#info-on-monolithic-architecture-and-microservices-architecture)



SONiC system's architecture comprises of various modules that interact among each other through a centralized and scalable infrastructure. This infrastructure relies on the use of a redis-database engine: a key-value database to provide a language independent interface, a method for data persistence, replication and multi-process communication among all SONiC subsystems.



SONiC places each module in independent docker containers to keep high cohesion among semantically-affine components, while reducing coupling between disjointed ones. Each of these components are written to be entirely independent of the platform-specific details required to interact with lower-layer abstractions.



#### SONiC Dockers



As of today, SONiC breaks its main functional components into the following docker containers:



```text

    Dhcp-relay

    Pmon

    Snmp

    Lldp

    Bgp

    Teamd

    Database

    Swss

    Syncd

```



#### Overview Diagram



<img src="https://github.com/Azure/SONiC/raw/master/images/sonic_user_guide_images/section4_images/section4_pic1_high_level.png" alt="image diagram" width="900" height="900"/>



#### SONiC Subsystems Description



1. dhcp-relay container: Enables the relay of DHCP requests from a subnet with no DHCP server, to one or

more DHCP servers on other subnets.



2. pmon container: Logs sensor readings from hardware components.

    - fancontrol: Collects fan-related state from the corresponding platform drivers.

    - sensord: Reads and logs sensor readings from hardware components, and alerts when an alarm is triggered.



3. snmp container: Hosts the SNMP features.

    - snmpd: Server that handles incoming SNMP polls from external network elements.

    - snmp_subagent: Inputs the snmpd server with information that is collected from SONiC databases in the centralized Redis engine.



4. lldp container: Hosts LLDP functionality.

    - lldpd: Establishes LLDP connections with external peers to advertise or receive system capabilities.

    - lldpmgrd: Provides incremental-configuration capabilities to LLDP daemon.

    - lldp_syncd: Uploads the discovered state of LLDP to the centralized message infrastructure in the Redis engine. By doing so, the LLDP state is delivered to applications such as SNMP that consume this information.



5. bgp container: Runs the supported routing stacks such as FRR. Although the container is named after the BGP routing protocol, these routing stacks can run various other protocols such as OSPF, IS-IS, LDP, and so on.

    - bgpd: Implements BGP functionality. The routing state from external entities is received through regular TCP/UDP sockets, and pushed to the forwarding plane through the zebra and fpmsyncd interfaces.

    - zebra: Acts as an IP routing manager that provides routing table updates for the kernel, interface-lookups, and route-redistribution services across different protocols. It pushes the computed FIB to kernel through Netlink interface, and to south-bound components involved in the forwarding process through Forwarding Plane Manager (FPM) interface.

    - fpmsyncd: Collects the FIB state that is generated by zebra and dumps its content into the APPL_DB table in the Redis server.



6. teamd container: Allows interaction between [*Link Aggregation functionality (LAG)*](#link-aggregation-functionality) and south-bound subsystems.

    - teamd: It is a linux-based open-source implementation of LAG protocol.

    - teamsyncd: Pushes the obtained state into the APPL_DB.



7. swss container: Switch State Service (swss) container is a suite of tools to coordinate communication among all the SONiC modules and the Redis engine. It hosts the processes incharge of the north-bound interaction with the SONiC application layer. The exception to this process is the fpmsyncd, teamsyncd and lldp_syncd processes that run within the context of bgp, teamd, and lldp containers respectively.

    - portsyncd: Listens to port-related Netlink events. During bootup, portsyncd obtains physical port information by parsing hardware profile config files. It pushes all the collected state into APPL_DB. Attributes such as port-speeds, lanes and MTU, and also injects the state into the STATE_DB.

    - intfsyncd: Listens to interface-related Netlink events and push collected state into APPL_DB. It handles the attributes such as new and changed ip-addresses that are associated to an interface.

    - neighsyncd: Listens to neighbor-related Netlink events triggered by newly discovered neighbors because of ARP processing. It handles the attributes such as the MAC address and the address family of the neighbor.

    - orchagent: Extracts all the relevant state that is injected by the syncd daemons, processes the information, and pushes data toward the south-bound interface, which is a database within the Redis engine. It operates both as a consumer (state coming from the APPL_DB), and also as a producer (state pushed into ASIC database).

    - intfmgrd: Responds to state arriving from APPL_DB, STATE_DB and CONFIG_DB to configure interfaces in the Linux kernel.

    - vlanmgrd: Responds to state arriving from APPL_DB, STATE_DB and CONFIG_DB to configure VLAN interfaces in the Linux kernel.

    - *database container:** Hosts the database for Redis engine. Databases that are held within this engine are accessible to SONiC applications through a UNIX socket exposed for this purpose by the Redis daemon.



The Redis engine hosts the following main databases:



1. APPL_DB: Stores the state that is generated by all application containers such as routes, next-hops, neighbors, and so on . This database is the south-bound entry point for all applications to interact with other SONiC subsystems.

2. CONFIG_DB: Stores the configuration state that is created by SONiC applications such as port configurations, interfaces, vlans, and so on.

3. STATE_DB: Stores key operational state for entities that are configured in the system. This state is used to resolve dependencies between different SONiC subsystems. For example, a LAG port channel (defined by teamd submodule) can potentially refer to physical ports that may or may not be present in the system.

4. ASIC_DB: Stores the necessary state to drive ASIC configuration and operation.

5. COUNTERS_DB: Stores counters or statistics that are associated to each port in the system.



syncd container: Contains the Switch

Abstraction Interface (SAI) library. All SAI programming requests are initiated by syncd, usually in response to Redis from various SONiC processes. It is the primary SONiC entry point into platform-specific services. The syncd process programs the networking ASIC through the SAI API. Cisco provides a SAI-friendly implementation of the ASIC SDK. Both the north-bound SAI API and ASIC SDK are coupled into a single shared library that is called the `libsai.so`.



#### CISCO 8000 Switch



The Cisco 8000 switch is a series of routers that deliver service provider-class routing functionality at data center switching density, performance, and power consumption. It is designed to provide high-density, high-performance routing for service providers and large enterprises.

The Cisco 8000 series routers are available in both fixed and modular form factors to address a wide range of use cases. The modular systems have one or two router processors, multiple line cards, multiple fabric cards, and chassis commons such as fans and power supply units.

The Cisco 8000 switch is used for securely connecting remote industrial operations, delivering peak industrial networking and SD-WAN performance with rugged all-in-one routing and switching, simplifying access networks, converging services with secure and programmable routers, and supporting the application performance required to power services with scalable routing systems.



<img src="https://www.cisco.com/c/en/us/products/routers/8000-series-routers/index/_jcr_content/Grid/subcategory_atl_581e/layout-subcategory-atl/anchor_info_b4b.img.png/1586190719152.png"  alt="image diagram"/>



### Installation



#### On CISCO 8000 Switch



```text

1. To install SONiC NOS on a Cisco 8000 switch, you can follow these steps:

2. Ensure that the switch has a boot loader such as Open Network Install Environment (ONIE) installed.

3. The SONiC Network Operating System (NOS) requires a boot loader to be installed.

4. Download the SONiC image for the ASIC vendor of your switch from the SONiC website.

5. Connect to the switch via serial console.

6. If the switch comes with a NOS that needs to be uninstalled before installing SONiC, boot into ONIE and select the option to uninstall the existing NOS.

7. Install the SONiC ONIE image on the switch by following the instructions provided in the ONIE Quick Start Guide.

8. When the NOS installation finishes, the switch will reboot into SONiC by default.

```



#### On CISCO 8000 Switch via PXE Boot



[Install SONiC on Cisco 8000 Series Routers Using PXE Boot](https://developer.cisco.com/docs/sonic/#!install-sonic-on-cisco-8000-series-routers/install-sonic-on-cisco-8000-series-routers-using-pxe-boot)



********************************************************************************************



## Other Notes



### Info on Monolithic Architecture and  Microservices Architecture



| Monolithic Architecture | Microservices Architecture |

| --- | --- |

| Built as one large system | Built as individual services |

| One code-base | Each service has its own codebase |

| Single-tiered software application | Multi-tiered software application |

| Different components combined into a single program from a single platform | Each service is self-contained and can be deployed independently of the others |

| Large and complex | Small and modular |

| Difficult to maintain and update the system as a whole | Easier to maintain and update the system as a whole |



#### Docker



```text

Docker is an open​​ platform for​​ developing, shipping​​, and running​​ applications​.

It enables​​ developers to​​ easily pack, ship​​, and run any​​ application as​​ a lightweight​​, portable, self​​-sufficient container​​ that can run​​ virtually anywhere​.

Here are​​ some reasons​​ why Docker is​​ useful:​

    - Portability: Docker containers are self-contained and can run on any Linux server without dependencies. This makes it easy to move applications between different environments.

    - Efficient use of resources: Docker containers use far less memory than virtual machines, and they start up instantly. They also have their own built-in mechanisms for versioning and component reuse.

    - Easier deployment: Docker makes it easier to put new versions of software with new business features into production quickly and to roll back to a previous version if needed. It also makes it easier to implement strategies like blue/green deployments.

    - Isolation: Docker containers provide isolation and security, allowing you to run many containers simultaneously on a given host. Containers are lightweight and contain everything needed to run the application, so you don't need to worry about dependencies

```



#### Azure



```text

Azure is a cloud computing platform and service offered by Microsoft.

```



#### APIs



```text

APIs (Application Programming Interfaces) are messaging formats that allow data to be transmitted from one system to another in near real-time.

APIs have become an essential and ubiquitous part of modern software development, from web-based services to mobile apps to IoT devices.

APIs empower developers to leverage the functionality and data of existing services and applications, making it easier and faster to build new software.

APIs are the connective tissue in today's ecosystems, and for companies who know how to implement them, they can cut costs, improve efficiency, and create a great customer experience.

The choice of an API format can have a profound and long-lasting impact on the success and adoption of an API.

APIs streamline the process of digital transformation by enabling applications to track and share data on orders, units produced, product defects, and much more.

The benefits of APIs include integration, scalability, stability, reliability, and security.

By using APIs, organizations can react to supply chain disruption, improve team collaboration, and provide services more efficiently.

```



#### Link aggregation functionality



```text

Link aggregation functionality (LAG) is a method of combining multiple network connections in parallel to increase total throughput beyond what a single connection can sustain. It provides redundancy where all but one of the physical links may fail without losing connectivity.

Here are some key points about LAG from the search results:

    - A LAG is a logical interface that uses the Link Aggregation Control Protocol (LACP) to aggregate multiple connections at a single endpoint, allowing them to be treated as a single, managed connection.

    - The combined collection of physical ports is called a link aggregation group (LAG).

    - LAGs multiply bandwidth, increase port flexibility, and provide link redundancy between two devices.

    - All the physical links in a given LAG must operate in full-duplex mode at the same speed.

    - The ports in a LAG can be manually configured (static) or automatically configured with LACP enabled.

    - Traffic forwarded to a LAG is load-balanced across the active member ports, achieving an effective bandwidth close to the aggregate bandwidth of all the active member ports of the LAG.

    - A LAG can be used to provide fast and transparent recovery in case one of the individual links fails.

```



#### Questions



**Question:** What is SWSS (Switch State Services) - Part of SONiC Arch?



> **Answer:** SWSS (Switch State Services) is a component of the SONiC (Software for Open Networking in the Cloud) architecture. SONiC is an open-source network operating system developed by Microsoft and contributed to the Open Compute Project. SWSS provides a framework for managing the switch state in a SONiC-based network. It includes various daemons responsible for handling different aspects of the switch's state, such as neighbor discovery, link aggregation, VLAN configuration, routing, and more.



**Question:** SAI (Switch Abstraction Interface) and its API?



> **Answer:** SAI (Switch Abstraction Interface) is an API (Application Programming Interface) that provides a standardized interface for communication between the switch hardware and the network operating system. It abstracts the underlying hardware-specific details and presents a uniform API that allows the network operating system to control and manage different switch ASICs (Application-Specific Integrated Circuits) without having to deal with their specific implementation details. SAI enables hardware independence and facilitates the development of network operating systems that can work with multiple switch platforms.



**Question:** Open Management Framework for Operational Simplicity and Automation - gNMI, RestConf etc?



> **Answer:** The Open Management Framework for Operational Simplicity and Automation encompasses various protocols and interfaces used for network management and automation. gNMI (gRPC Network Management Interface) and RESTCONF are two such protocols. gNMI is a network management protocol based on gRPC (Google Remote Procedure Call) that provides a standardized way to retrieve, configure, and monitor network device parameters. RESTCONF is a RESTful protocol based on the NETCONF (Network Configuration Protocol) standard that enables similar functionalities through HTTP-based interactions. These protocols help simplify network management tasks and enable automation by providing programmable interfaces to network devices.



**Question:** Customer Pain Points - What is Legacy 3-tier arch (based on OEM solution)?



> **Answer:** Legacy 3-tier architecture based on OEM (Original Equipment Manufacturer) solutions refers to traditional networking deployments that typically involve a hierarchical structure with access switches, distribution switches, and core switches. These architectures often rely on proprietary solutions from specific vendors, which can result in vendor lock-in, limited flexibility, and higher costs. Customer pain points associated with such architectures include lack of interoperability, limited scalability, complex management, and dependence on a single vendor for feature enhancements and support.



**Question:** Spines based on Tomahawk 2?



> **Answer:** Spines based on Tomahawk 2 refers to the use of switches equipped with the Tomahawk 2 ASIC in the spine layer of a network fabric. Tomahawk 2 is a high-performance, programmable switch ASIC developed by Broadcom. It offers advanced features such as high port density, deep buffering, low-latency packet processing, and support for high-speed interfaces (e.g., 100 Gigabit Ethernet). By utilizing switches based on Tomahawk 2, network architectures can benefit from increased capacity, improved performance, and enhanced scalability.



**Question:** Leaf switched based on Trident 3?



> **Answer:** Leaf switches based on Trident 3 refers to the use of switches powered by the Trident 3 ASIC in the leaf layer of a network fabric. Trident 3 is another switch ASIC developed by Broadcom, designed for data center and cloud networking environments. It provides features like high port density, line-rate forwarding, advanced congestion management, and support for various networking protocols. Trident 3-based leaf switches offer a combination of performance, flexibility, and programmability, making them suitable for connecting end devices in a network fabric.



**Question:** VXLAN EVPN based fabric providing multi-tenancy?



> **Answer:** VXLAN EVPN (Virtual Extensible LAN Ethernet Virtual Private Network) is a network fabric architecture that leverages VXLAN for overlay encapsulation and the EVPN protocol for control plane functionalities. It provides a scalable and efficient solution for building multi-tenant networks, allowing different tenants to have isolated virtual networks (VXLAN segments) over a shared physical infrastructure. VXLAN EVPN enables features like tenant segmentation, optimal forwarding, efficient workload mobility, and simplified network provisioning in cloud and data center environments.



**Question:** BGV as Underlay and Overlay protocol?



> **Answer:** BGV (BGP-VXLAN Gateway) acts as both the underlay and overlay protocol in a VXLAN EVPN fabric. BGV combines the Border Gateway Protocol (BGP) and VXLAN technologies to provide connectivity and communication between different VXLAN segments. BGP is used as the underlay protocol to exchange routing information between the BGV devices, enabling reachability across the physical network infrastructure. VXLAN, on the other hand, is utilized as the overlay protocol to encapsulate tenant traffic and extend Layer 2 connectivity across the fabric.



**Question:** Inter and Intra POD?



> **Answer:** Inter-Pod and Intra-Pod refer to different levels of connectivity within a data center fabric.

Inter-Pod refers to the connectivity between different pods or data center sections. Pods are logical or physical units that group together a set of resources like compute, storage, and networking. Inter-Pod connectivity allows communication and workload mobility between different pods, enabling scalability and resilience across the entire data center infrastructure.

Intra-Pod, on the other hand, refers to the connectivity within a single pod. It encompasses the networking elements within the same pod, such as the leaf switches, spine switches, and the associated network fabric. Intra-Pod connectivity ensures efficient and low-latency communication between devices within the same pod, facilitating the seamless operation of applications and services.



**Question:** Deep visibility with Silicon based Telemetry?



> **Answer:** Deep visibility with Silicon-based Telemetry refers to the ability to gain detailed insights and monitoring data from network devices by leveraging the capabilities of silicon (hardware) telemetry. Silicon-based telemetry utilizes specialized hardware features within network devices, such as programmable ASICs, to collect and export real-time data about network traffic, performance metrics, and events. This telemetry data provides deep visibility into the inner workings of the network, enabling network operators to troubleshoot issues, optimize performance, and make informed decisions based on real-time network intelligence. By leveraging silicon-based telemetry, operators can obtain granular visibility without significant impact on device performance.
