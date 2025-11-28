//
//  BioTrustBridge.h
//  BiometricFaceValidator
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Interface pública do BioTrust para criptografia e autenticação biométrica
 */
@interface BioTrustBridge : NSObject

/**
 * Inicializa a biblioteca OpenSSL
 * Deve ser chamado antes de usar qualquer função de criptografia
 */
+ (void)initialize;

/**
 * Limpa recursos da biblioteca OpenSSL
 * Deve ser chamado quando não precisar mais das funções
 */
+ (void)cleanup;

/**
 * Criptografa um texto usando AES-256-CBC
 * @param plaintext Texto a ser criptografado
 * @return Texto criptografado em Base64 ou nil se houver erro
 */
+ (nullable NSString *)encrypt:(NSString *)plaintext;

/**
 * Descriptografa um texto criptografado
 * @param ciphertext Texto criptografado em Base64
 * @return Texto descriptografado ou nil se houver erro
 */
+ (nullable NSString *)decrypt:(NSString *)ciphertext;

/**
 * Gera payload de autenticação criptografado
 * @param packageName Nome do pacote da aplicação
 * @param uuid Identificador único do dispositivo
 * @param validationType Tipo de validação (ex: "face", "fingerprint")
 * @param document Número do documento
 * @param dob Data de nascimento (formato: YYYY-MM-DD)
 * @param deviceID Device identifier
 * @param sdkVersion SDK version
 * @param so Operating system
 * @param soVersion OS version
 * @param ipAddress IP address
 * @param requestId FingerprintJS request ID
 * @return Payload criptografado em Base64 ou nil se houver erro
 */
+ (nullable NSString *)generateAuthPayloadWithPackageName:(NSString *)packageName
                                                     uuid:(NSString *)uuid
                                           validationType:(NSString *)validationType
                                                 document:(NSString *)document
                                                      dob:(NSString *)dob
                                                 deviceID:(NSString *)deviceID
                                               sdkVersion:(NSString *)sdkVersion
                                                       so:(NSString *)so
                                                soVersion:(NSString *)soVersion
                                                ipAddress:(NSString *)ipAddress
                                                requestId:(NSString *)requestId;

@end

NS_ASSUME_NONNULL_END
