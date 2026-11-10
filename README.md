# BioTrust for iOS

Facial biometrics: liveness detection, document verification, FaceMatch identification and
continuous access control. Binary distribution of the BioTrust iOS SDK for Swift Package
Manager.

## Requirements

| Item | Value |
| --- | --- |
| iOS | 15.0 or newer |
| Architecture | arm64, physical device only |
| Xcode | 15 or newer |
| Credentials | Client UUID, available in the Dashboard |

The package does not include a simulator slice. Validation requires the device camera.

## Installation

In Xcode, under **File › Add Package Dependencies**, enter:

```
https://github.com/biotrust-io/BioTrust-SDK-IOS-Release
```

Or in `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/biotrust-io/BioTrust-SDK-IOS-Release", from: "1.2.1")
]
```

The `BioTrust` product delivers two binaries: the SDK and FingerprintPro, which the SDK links
at runtime. Swift Package Manager adds both to the project.

## Permissions

```xml
<key>NSCameraUsageDescription</key>
<string>The camera is used to verify your identity.</string>
```

## Documentation

The usage reference, covering validation modes, parameters, results, FaceMatch and access
control, is available at
[docs.biotrust.io](https://docs.biotrust.io/docs/1.2.1/ios/getting-started).

## License

Proprietary software, licensed for use with the BioTrust services under a commercial
agreement. The full text is available at
[docs.biotrust.io/licenca.txt](https://docs.biotrust.io/licenca.txt) and in the `LICENSE` file
of this repository.

Support: cloud@biotrust.io
