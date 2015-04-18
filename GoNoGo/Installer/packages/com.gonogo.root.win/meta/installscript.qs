function Component() {
    // default constructor
}

Component.prototype.createOperations = function() {
    component.createOperations();

    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", "@TargetDir@/GoNoGo.exe", "@StartMenuDir@/Go No Go.lnk",
            "workingDirectory=@TargetDir@", "iconPath=@TargetDir@/GoNoGo.exe",
            "iconId=0");

		component.addOperation("CreateShortcut", "@TargetDir@/.up/up.bat", "@StartMenuDir@/Update Go No Go.lnk",
            "workingDirectory=@TargetDir@", "iconPath=@TargetDir@/updater.exe",
            "iconId=0");
    }
}