function Component() {
    // default constructor
	installer.installationFinished.connect(this, Component.prototype.installationFinishedPageIsShown);
}

Component.prototype.installationFinishedPageIsShown = function() {
	try {
        if (installer.isInstaller() && installer.status == QInstaller.Success) {
			console.log("Opening DirectX installer.");
            QDesktopServices.openUrl("file:///" + installer.value("TargetDir") + "/dxdep/dx.bat");
        }
    } catch(e) {
        console.log(e);
    }
}

Component.prototype.createOperationsForArchive = function(archive) {
    if (systemInfo.productType === "windows") {
        component.addOperation("Extract", archive, "@TargetDir@/dxdep");
    }
}