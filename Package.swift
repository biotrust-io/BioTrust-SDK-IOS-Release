// swift-tools-version:6.0

import PackageDescription

let package = Package(
    name: "BioTrust",
    platforms: [
        .iOS(.v12) // ajuste para a versão mínima compatível com seu xcframework
    ],
    products: [
        .library(
            name: "BioTrust",
            targets: ["BioTrust"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "BioTrust",
            path: "./XCFrameworks/BioTrust.xcframework"
        )
    ]
)
