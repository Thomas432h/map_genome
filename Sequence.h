#ifndef SEQUENCE_H // Directive de préprocesseur pour éviter les inclusions multiples du fichier d'en-tête
#define SEQUENCE_H

#include <string> // Inclusion de la bibliothèque pour utiliser des chaînes de caractères

class Sequence { // Déclaration de la classe Sequence
private: // Section privée de la classe, accessible uniquement à l'intérieur de la classe
    std::string id; // Identifiant de la séquence
    std::string sequence; // Séquence ADN
    std::string quality; // Qualité de la séquence
    std::string sourceFile; // Fichier source de la séquence

public: // Section publique de la classe, accessible depuis l'extérieur de la classe
    Sequence(const std::string& id, const std::string& sequence, const std::string& quality, const std::string& sourceFile); // Constructeur de la classe

    const std::string& getId() const; // Méthode pour obtenir l'identifiant de la séquence
    const std::string& getSequence() const; // Méthode pour obtenir la séquence ADN
    size_t length() const; // Méthode pour obtenir la longueur de la séquence ADN
    const std::string& getQuality() const; // Méthode pour obtenir la qualité de la séquence
    const std::string& getSourceFile() const; // Méthode pour obtenir le fichier source de la séquence
};

#endif // Fin de la directive de préprocesseur et du fichier d'en-tête
