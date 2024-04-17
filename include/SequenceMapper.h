#ifndef SEQUENCE_MAPPER_H // Directive de préprocesseur pour éviter les inclusions multiples du fichier d'en-tête
#define SEQUENCE_MAPPER_H

#include "FastqReader.h" // Inclusion du fichier d'en-tête de la classe FastqReader
#include "TableSuffixes.h" // Inclusion du fichier d'en-tête de la classe TableSuffixes
#include <iostream> // Inclusion de la bibliothèque pour les entrées/sorties
#include <vector> // Inclusion de la bibliothèque pour utiliser des vecteurs
#include <string> // Inclusion de la bibliothèque pour utiliser des chaînes de caractères
#include <unordered_map> // Inclusion de la bibliothèque pour utiliser des tables de hachage non ordonnées

class SequenceMapper { // Déclaration de la classe SequenceMapper
public: // Section publique de la classe, accessible depuis l'extérieur de la classe
    SequenceMapper(FastqReader& reader, TableSuffixes& table, const std::string& sequenceId); // Constructeur de la classe
    void mapReads(); // Méthode pour effectuer le mapping des k-mers
    void displayMapping(); // Méthode pour afficher les résultats du mapping
    void performAlignment(); // Méthode pour effectuer l'alignement basé sur les mappings

private: // Section privée de la classe, accessible uniquement à l'intérieur de la classe
    FastqReader& fastqReader; // Référence vers un objet FastqReader
    TableSuffixes& suffixTable; // Référence vers un objet TableSuffixes
    std::string sequenceId; // Identifiant de la séquence
    std::unordered_map<std::string, std::vector<std::pair<int, int>>> mappings; // Tableau associatif pour stocker les k-mers et leurs positions (lecture, référence)

    void alignRead(const std::string& kmer, int readPosition, int referencePosition); // Méthode pour aligner une lecture avec une référence
};

#endif // Fin de la directive de préprocesseur et du fichier d'en-tête
