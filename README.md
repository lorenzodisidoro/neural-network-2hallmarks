# Neural network for two hallmarks

This is a simple neural network implementation to detect two types of elements that have two hallmarks. 
The network will trained with data in the `training_dataset.csv` file, users interact with CLI to insert new values pairs.

File structure of training dataset

| First Hallmark | Second Hallmark | Element Type |
| :---         |     :---:      |          ---: |
| 2.1   | 5.11     | 1    |
| 3.1     | 4.91       | 1      |
| 9.2     | 7.61       | 0      |
| 1.6     | 4.85       | 1      |
| 8.4     | 7.46       | 0      |
| ...     | ...       | ...      |

## Build
Clone this repository using

```sh
$ git clone https://github.com/lorenzodisidoro/neural-network-2hallmarks.git
```

then build using make command in project directory

```sh
$ make
```
