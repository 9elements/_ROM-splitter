# _ROM-splitter

temporary workaround to get ACPI _ROM Method for Nvidia GPUs in optimus configuration

It takes a vbios ROM file, splits it into 4KB chunks,

and creates a bunch of ACPI Methods to provide that vbios

in the 4KB chunks that the nvidia driver expects.

Qemu fw cfg mechanism would be superior to this, but it has been

tested to work and requires no patches to qemu/ovmf.
