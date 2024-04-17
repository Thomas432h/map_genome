#include "SequenceReader.h" // Inclusion du fichier d'en-tête de la classe SequenceReader
#include <fstream> // Inclusion de la bibliothèque pour la gestion des fichiers
#include <iostream> // Inclusion de la bibliothèque pour les entrées/sorties

std::vector<Sequence> SequenceReader::readSequences(const std::string& filename) { // Définition de la méthode readSequences de la classe SequenceReader
    std::ifstream file(filename); // Ouverture du fichier en lecture
    std::vector<Sequence> sequences; // Initialisation d'un vecteur pour stocker les séquences
    if (!file.is_open()) { // Vérification de l'ouverture réussie du fichier
        std::cerr << "Error opening file " << filename << std::endl; // Affichage d'un message d'erreur si l'ouverture du fichier échoue
        return sequences; // Retourne un vecteur vide en cas d'échec
    }

    std::string line, id, seq, qual; // Déclaration de variables pour stocker les lignes, l'identifiant, la séquence et la qualité
    bool isFASTQ = false; // Variable pour indiquer si le fichier est au format FASTQ
    int lineCount = 0; // Variable pour compter les lignes du fichier

    while (getline(file, line)) { // Lecture des lignes du fichier
        if (line.empty()) continue; // Ignorer les lignes vides

        if (line[0] == '>' || line[0] == '@') { // Vérifier si la ligne est un en-tête de séquence FASTA ou FASTQ
            if (!id.empty()) { // Vérifier si des données de séquence ont été collectées précédemment
                // Pass the filename to the Sequence constructor
                sequences.emplace_back(id, seq, qual, filename); // Ajouter la séquence précédente au vecteur de séquences
                seq.clear(); // Réinitialiser la variable de séquence
                qual.clear(); // Réinitialiser la variable de qualité
            }
            id = line.substr(1); // Extraire l'identifiant de la séquence
            isFASTQ = (line[0] == '@'); // Déterminer si le fichier est au format FASTQ
            lineCount = 0;  // Réinitialiser le compteur de lignes pour FASTQ
        } else if (isFASTQ && (lineCount % 4 == 3)) {
            qual = line;  // Stocker la ligne de qualité pour FASTQ
        } else if (!isFASTQ || (lineCount % 4 == 1)) {
            seq += line;  // Accumuler la séquence pour FASTA et la ligne de séquence pour FASTQ
        }

        if (isFASTQ) lineCount++; // Incrémenter le compteur de lignes pour FASTQ
    }

    if (!id.empty()) {
        // Passer le nom du fichier au constructeur de Sequence pour la dernière séquence
        sequences.emplace_back(id, seq, qual, filename); // Ajouter la dernière séquence au vecteur de séquences
    }

    file.close(); // Fermer le fichier
    return sequences; // Retourner le vecteur de séquences
}
