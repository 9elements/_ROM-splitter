DefinitionBlock ("", "SSDT", 1, "JSC", "NVHACK", 0x00000002) {

    External(RO99, MethodObj)

    Device (\_SB.PCI0.PEG0) {
    //Device (\_SB_.PCI0.S08_) {
        //https://uefi.org/htmlspecs/ACPI_Spec_6_4_html/06_Device_Configuration/Device_Configuration.html
        //for pci: high word: device slot, low word: function
        Name (_ADR, 0x00010000)
    }

    Device (\_SB.PCI0.PEG0.PEGP) {
    //Device (\_SB_.PCI0.S08_.S00_) {
        Name (_ADR, Zero)
    }

    Scope (\_SB.PCI0.PEG0.PEGP) {
    //Scope (\_SB_.PCI0.S08_.S00_) {

        Method (_ROM, 2, NotSerialized) {

            Local2 = RO00(Arg0, Arg1)
            return (Local2)
        }

        Method(RO99, 2, NotSerialized){
            Local0 = Buffer(1){0x00}
            return (Local0)
        }
    }
}
