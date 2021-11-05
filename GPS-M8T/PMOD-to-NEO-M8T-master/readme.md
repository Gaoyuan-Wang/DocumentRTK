# PMOD to NEO-M8T

Simple board to connect a uBlox NEO-M8T gps module to an extended SPI (type 2A) PMOD connection.

| ID     | Value                  | Package | Notes                                                |
| ------ | ---------------------- | ------- | ---------------------------------------------------- |
| C1, C2 | 10 nF, 16V, 10%        | 0402    | Decoupling caps for VIN and for active antenna power |
| C3     | 47 pF, 25V, 5%         | 0402    | DC blocking cap for RF IN                            |
| R1     | 10 Ohm, >1/4 watt, 10% | 0805    | Active antenna bias resistor                         |
| L1     | 27 nH, 5%              | 0402    | Blocks RF input from active antenna power supply     |

[Project Log](https://hackaday.io/project/119133-rops/log/139591-pmod-to-neo-m8t)

[Board at OSH Park](https://oshpark.com/shared_projects/ygiuimwL)
