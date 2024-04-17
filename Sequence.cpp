#include "Sequence.h"

// Constructeur de la classe Sequence
Sequence::Sequence(const std::string& id, const std::string& sequence, const std::string& quality, const std::string& sourceFile)
    : id(id), sequence(sequence), quality(quality), sourceFile(sourceFile) {}

// Méthode pour obtenir l'identifiant de la séquence
const std::string& Sequence::getId() const {
    return id;
}

// Méthode pour obtenir la séquence
const std::string& Sequence::getSequence() const {
    return sequence;
}

// Méthode pour obtenir la longueur de la séquence
size_t Sequence::length() const {
    return sequence.length();
}

// Méthode pour obtenir la qualité de la séquence
const std::string& Sequence::getQuality() const {
    return quality;
}

// Méthode pour obtenir le fichier source de la séquence
const std::string& Sequence::getSourceFile() const {
    return sourceFile;
}
