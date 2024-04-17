#include "FastqReader.h"
#include <fstream> // Pour la lecture de fichiers
#include <iostream> // Pour l'affichage
#include <sstream> // Pour la manipulation de chaînes de caractères
#include <algorithm> // Pour les opérations sur les séquences

// Constructeur par défaut de FastqReader
FastqReader::FastqReader() {}

// Destructeur de FastqReader
FastqReader::~FastqReader() {}

// Méthode pour traiter un fichier FASTQ
void FastqReader::processFastqFile(const std::string& filePath, int qualityThreshold, int kmerLength) {
    // Ouverture du fichier
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filePath << std::endl;
        return;
    }

    std::string id, sequence, plus, quality;
    // Lecture de chaque entrée FASTQ
    while (std::getline(file, id) && id[0] == '@') {
        // Lecture de la séquence, du caractère '+' et de la qualité
        if (!std::getline(file, sequence) || !std::getline(file, plus) || !std::getline(file, quality)) {
            break; // Arrêt si l'une des lectures échoue
        }

        // Stockage de la séquence
        sequences += sequence + "\n";

        // Filtrage de la séquence en fonction de la qualité
        std::string filteredSequence = filterReadByQuality(sequence, quality, qualityThreshold);

        // Stockage des reads filtrés
        filteredReads += filteredSequence + "\n";

        // Génération des k-mers à partir de la séquence filtrée et stockage
        generateKmers(filteredSequence, kmerLength);
    }

    file.close(); // Fermeture du fichier
}

// Méthode pour filtrer une séquence en fonction de la qualité
std::string FastqReader::filterReadByQuality(const std::string& sequence, const std::string& quality, int qualityThreshold) const {
    std::string filteredRead;
    for (size_t i = 0; i < sequence.length() && i < quality.length(); i++) {
        if (quality[i] - 33 >= qualityThreshold) {
            filteredRead += sequence[i];  // Conserve la base si la qualité est suffisante
        } else {
            filteredRead += '-';  // Insère un gap si la qualité est insuffisante
        }
    }
    return filteredRead;
}

// Méthode pour générer les k-mers à partir d'une séquence filtrée
void FastqReader::generateKmers(const std::string& sequence, int kmerLength) {
    int n = sequence.length();
    for (int i = 0; i <= n - kmerLength; ++i) {
        std::string kmer = sequence.substr(i, kmerLength);
        kmers[kmer].push_back(i);  // Ajoute la position du k-mer à la liste de ses occurrences
    }
}

// Méthode pour afficher les résultats
void FastqReader::printResults() const {
    // Afficher les séquences
    std::cout << "Séquences :" << std::endl;
    std::cout << sequences << std::endl;

    // Afficher les reads filtrés
    std::cout << "Reads filtrés :" << std::endl;
    std::cout << filteredReads << std::endl;

    // Afficher les k-mers et leurs positions
    std::cout << "K-mers et leurs positions stockées :" << std::endl;
    for (const auto& pair : kmers) {
        std::cout << "K-mer : " << pair.first << " - Positions : ";
        for (int pos : pair.second) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    }
}
