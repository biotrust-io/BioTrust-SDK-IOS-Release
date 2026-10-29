# BioTrust para iOS

Validação biométrica facial: prova de vida, validação com documento, FaceMatch e controle de
acesso. Distribuição binária do SDK iOS BioTrust para Swift Package Manager.

## Requisitos

| Item | Valor |
| --- | --- |
| iOS | 15.0 ou superior |
| Arquitetura | arm64, somente aparelho físico |
| Xcode | 15 ou superior |
| Credencial | UUID do cliente, obtido no Dashboard |

O pacote não inclui fatia de simulador. A validação depende da câmera do aparelho.

## Instalação

No Xcode, em **File › Add Package Dependencies**, informe:

```
https://github.com/biotrust-io/BioTrust-SDK-IOS-Release
```

Ou no `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/biotrust-io/BioTrust-SDK-IOS-Release", from: "1.1.0")
]
```

O produto `BioTrust` entrega dois binários: o SDK e o FingerprintPro, que ele referencia em
tempo de execução. Ambos são adicionados ao projeto pelo Swift Package Manager.

## Permissões

```xml
<key>NSCameraUsageDescription</key>
<string>A câmera é utilizada para a validação da sua identidade.</string>
```

## Documentação

A referência de uso — modos de validação, parâmetros, resultado, FaceMatch e controle de
acesso — está em
[docs.biotrust.io](https://docs.biotrust.io/docs/1.2.0/ios/getting-started).

## Licença

Software proprietário, licenciado para uso com os serviços BioTrust mediante contrato
comercial. O texto completo está em
[docs.biotrust.io/licenca.txt](https://docs.biotrust.io/licenca.txt) e no arquivo `LICENSE`
deste repositório.

Suporte: cloud@biotrust.io
