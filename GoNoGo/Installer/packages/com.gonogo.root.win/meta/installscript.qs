function Component() {
    // default constructor
}

Component.prototype.createOperations = function() {
    component.createOperations();

    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", "@TargetDir@/GoNoGo.exe", "@StartMenuDir@/GoNoGo.lnk",
            "workingDirectory=@TargetDir@", "iconPath=@TargetDir@/GoNoGo.exe",
            "iconId=0");
    }
}