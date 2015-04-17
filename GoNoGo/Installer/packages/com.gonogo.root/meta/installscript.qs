function Component() {
    // OS Check
	// start installer with -v for debug output
    console.log("OS: " + systemInfo.productType);
    console.log("Kernel: " + systemInfo.kernelType + "/" + systemInfo.kernelVersion);
	
	installer.componentByName("com.gonogo.root.win").setValue("Virtual", "true");
    installer.componentByName("com.gonogo.root.mac").setValue("Virtual", "true");
	installer.componentByName("com.gonogo.root.dx").setValue("Virtual", "true");
	
	if (systemInfo.kernelType === "winnt") {
		installer.componentByName("com.gonogo.root.win").setValue("Virtual", "false");
        installer.componentByName("com.gonogo.root.win").setValue("Default", "true");
		installer.componentByName("com.gonogo.root.dx").setValue("Virtual", "false");
		installer.componentByName("com.gonogo.root.dx").setValue("Default", "true");
	}
	
	if (systemInfo.kernelType === "darwin") {
		installer.componentByName("com.gonogo.root.mac").setValue("Virtual", "false");
        installer.componentByName("com.gonogo.root.mac").setValue("Default", "true");
	}
}