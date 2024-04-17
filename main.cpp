#include <iostream> // Inclusion de la bibliothèque pour les entrées/sorties standard
#include <filesystem> // Inclusion de la bibliothèque pour la manipulation des fichiers et des répertoires
#include <vector> // Inclusion de la bibliothèque pour utiliser des vecteurs
#include "SequenceReader.h" // Inclusion du fichier d'en-tête de la classe SequenceReader
#include "TableSuffixes.h" // Inclusion du fichier d'en-tête de la classe TableSuffixes
#include "FastqReader.h" // Inclusion du fichier d'en-tête de la classe FastqReader
#include "SequenceMapper.h" // Inclusion du fichier d'en-tête de la classe SequenceMapper

namespace fs = std::filesystem; // Alias pour simplifier l'utilisation de std::filesystem

int main() { // Début de la fonction principale du programme

    // Définition des chemins des répertoires de fichiers FASTA et FASTQ
    std::string fastaPath = "data";
    std::string fastqPath = "data_read";

    SequenceReader reader; // Création d'un objet SequenceReader pour la lecture des séquences
    bool fastaFileFound = false, fastqFileFound = false; // Déclaration de variables pour indiquer si des fichiers FASTA et FASTQ ont été trouvés

    std::vector<TableSuffixes> suffixTables; // Déclaration d'un vecteur pour stocker les tables de suffixes des séquences FASTA
    FastqReader fastqReader; // Création d'un objet FastqReader pour la lecture des fichiers FASTQ
    std::string lastSequenceId; // Déclaration d'une variable pour stocker l'ID de la dernière séquence traitée

    // Étape 1 : Lecture des fichiers FASTA et création des tables de suffixes
    std::cout << "Lecture des fichiers FASTA et création des tables de suffixes :" << std::endl;
    for (const auto& entry : fs::directory_iterator(fastaPath)) { // Parcours des fichiers dans le répertoire FASTA
        if (entry.path().extension() == ".fasta" || entry.path().extension() == ".fa") { // Vérification de l'extension du fichier
            fastaFileFound = true; // Indication qu'au moins un fichier FASTA valide a été trouvé
            auto sequences = reader.readSequences(entry.path()); // Lecture des séquences dans le fichier FASTA
            for (const auto& seq : sequences) { // Parcours de chaque séquence lue
                // Affichage des informations sur chaque séquence
                std::cout << "ID: " << seq.getId() << "\nSequence: " << seq.getSequence()
                          << "\nLength: " << seq.length() 
                          << "\nSource File: " << seq.getSourceFile() << std::endl;
                lastSequenceId = seq.getId(); // Mise à jour de l'ID de la dernière séquence traitée
                TableSuffixes suffixTable(seq); // Création d'une table de suffixes pour la séquence actuelle
                suffixTables.push_back(suffixTable); // Ajout de la table de suffixes au vecteur
            }
        }
    }

    // Étape 2 : Affichage de toutes les tables de suffixes
    std::cout << "Affichage de toutes les tables de suffixes :" << std::endl;
    for (const auto& suffixTable : suffixTables) { // Parcours de chaque table de suffixes dans le vecteur
        suffixTable.printAllSuffixTables(); // Appel de la fonction pour afficher la table de suffixes
    }

    // Étape 3 : Traitement des fichiers FASTQ et mapping des lectures
    std::cout << "Traitement des fichiers FASTQ et mapping des lectures :" << std::endl;
    for (const auto& entry : fs::directory_iterator(fastqPath)) { // Parcours des fichiers dans le répertoire FASTQ
        if (entry.path().extension() == ".fastq" || entry.path().extension() == ".fq") { // Vérification de l'extension du fichier
            fastqFileFound = true; // Indication qu'au moins un fichier FASTQ valide a été trouvé
            std::cout << "Fichier FASTQ trouvé : " << entry.path() << std::endl; // Affichage du chemin du fichier FASTQ

            fastqReader.processFastqFile(entry.path(), 20, 10); // Traitement du fichier FASTQ
            fastqReader.printResults(); // Affichage des résultats du traitement

            // Création du mapper et mapping des lectures
            SequenceMapper mapper(fastqReader, suffixTables.back(), lastSequenceId); // Création d'un objet SequenceMapper
            mapper.mapReads(); // Appel de la fonction pour mapper les lectures
            mapper.displayMapping();  // Affichage du mapping
        }
    }

    // Gestion des erreurs si aucun fichier FASTA ou FASTQ valide n'a été trouvé
    if (!fastaFileFound) {
        std::cerr << "Erreur : Aucun fichier FASTA valide trouvé dans 'data'." << std::endl;
    }
    if (!fastqFileFound) {
        std::cerr << "Erreur : Aucun fichier FASTQ valide trouvé dans 'data_read'." << std::endl;
    }

    return 0; // Fin du programme
}
