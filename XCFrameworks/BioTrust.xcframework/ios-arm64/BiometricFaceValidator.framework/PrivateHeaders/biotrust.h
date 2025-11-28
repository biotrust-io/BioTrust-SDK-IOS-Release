#ifndef BIOTRUST_H
#define BIOTRUST_H

#include <string>

class BioTrust {
public:
    // Inicialização e limpeza
    static void Initialize();
    static void Cleanup();
    
    // Métodos de criptografia usando CommonCrypto nativo
    static std::string Encrypt(const std::string& plaintext);
    static std::string Decrypt(const std::string& ciphertext);
    
    // Método para gerar payload de autenticação
    static std::string GenerateAuthPayload(
        const std::string& packageName,
        const std::string& uuid,
        const std::string& validationType,
        const std::string& document,
        const std::string& dob,
        const std::string& deviceID,
        const std::string& sdkVersion,
        const std::string& so,
        const std::string& soVersion,
        const std::string& ipAddress,
        const std::string& requestId
    );
};

#endif // BIOTRUST_H
