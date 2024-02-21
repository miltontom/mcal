# mcal

Get linux file permissions in numeric format from the command-line.

## Setup

* The binaries are available in the respective folders based on the OS
* Add the binaries to the `PATH` to use it anywhere from the CLI. 

## How to use?

Running `mcal` with no argument gives,

```bash
Usage
        mcal <symbolic_permissions>

Description
        A command-line 'chmod' calculator.

Notes
        * Symbolic permission format: [owner][group][public]
        * Certain permissions can be omitted with '-'

Examples
        mcal rwxrwxrwx  -> 777
        mcal rwxrw-rw-  -> 766
        mcal rwx------  -> 700
```
