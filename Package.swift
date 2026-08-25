// swift-tools-version:6.0

import PackageDescription

let package = Package(
    name: "BioTrust",
    platforms: [
        .iOS(.v15)
    ],
    products: [
        .library(
            name: "BioTrust",
            targets: ["BioTrust", "FingerprintPro"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "BioTrust",
            path: "./XCFrameworks/BioTrust.xcframework"
        ),
        .binaryTarget(
            name: "FingerprintPro",
            path: "./XCFrameworks/FingerprintPro.xcframework"
        )
    ]
)
