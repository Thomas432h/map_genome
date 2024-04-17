#ifndef FASTQ_READER_H
#define FASTQ_READER_H

#include <string> // Inclusion de la bibliothèque pour les chaînes de caractères
#include <unordered_map> // Inclusion de la bibliothèque pour les tables de hachage
#include <vector> // Inclusion de la bibliothèque pour les vecteurs

class FastqReader {
public:
    FastqReader(); // Déclaration du constructeur par défaut
    ~FastqReader(); // Déclaration du destructeur

    void processFastqFile(const std::string& filePath, int qualityThreshold, int kmerLength); // Déclaration de la méthode pour traiter un fichier FASTQ
    void printResults() const; // Déclaration de la méthode pour afficher les résultats

    // Ajout de la méthode pour obtenir les k-mers
    const std::unordered_map<std::string, std::vector<int>>& getKmers() const { // Déclaration de la méthode pour obtenir les k-mers
        return kmers; // Retourne les k-mers
    }

private:
    std::unordered_map<std::string, std::vector<int>> kmers; // Table de hachage pour stocker les k-mers

    std::string filterReadByQuality(const std::string& sequence, const std::string& quality, int qualityThreshold) const; // Déclaration de la méthode pour filtrer les lectures par qualité
    void generateKmers(const std::string& sequence, int kmerLength); // Déclaration de la méthode pour générer les k-mers

    std::string sequences; // Chaîne de caractères pour stocker les séquences
    std::string filteredReads; // Chaîne de caractères pour stocker les lectures filtrées
    std::string kmersInfo; // Chaîne de caractères pour stocker les informations sur les k-mers
};

#endif // FASTQ_READER_H
