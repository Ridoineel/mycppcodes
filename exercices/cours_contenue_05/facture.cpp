#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Article {
	std::string libelle;
	int code;
	float prix;
};

struct ArticleAchetee {
	Article article;
	int nbre;
	float prixTotal;
};

void initArticles(vector<Article>& articles) {
	Article 
		centrifugeuse,
		grillePain,
		fourARaclette6P;

	centrifugeuse.libelle = "Centrifugeuse";
	centrifugeuse.prix = 3700;
	centrifugeuse.code = 25;

	grillePain.libelle = "Grille Pain";
	grillePain.prix = 1995;
	grillePain.code = 7;

	fourARaclette6P.libelle = "Four a raclette 6P";
	fourARaclette6P.prix = 2952;
	fourARaclette6P.code = 26;

	articles.push_back(centrifugeuse);
	articles.push_back(grillePain);
	articles.push_back(fourARaclette6P);
}

void afficherArticles(vector<Article> articles) {
	cout << setw(30) << "Libelle" << setw(20) << "Prix" << setw(20) << "Code" << endl << endl; 

	for (int i = 0; i < articles.size(); i++) {
		Article article = articles[i];

		cout << setw(30) << article.libelle << setw(20) << article.prix << setw(20) << article.code << endl;
	}
}

Article getArticle(vector<Article> articles, int codeArticle) {
	Article article;

	for (int i=0; i < articles.size(); i++) {
		if (articles[i].code == codeArticle) {
			article = articles[i];
			break;
		}
	}

	return article;
}

void afficherFacture(vector<ArticleAchetee> panier) {
	ArticleAchetee articleAchetee;
	cout << endl;
	cout << "				*** FACTURE ***" << endl;
	cout << endl;

	cout << setw(20) << "ARTICLE" << setw(10) << "NBRE" << setw(20) << "P-UNIT" << setw(20) << "MONTANT" << endl;
	for (int i=0; i < panier.size(); i++) {
		articleAchetee = panier[i];

		cout 
			<< setw(20) << articleAchetee.article.libelle 
			<< setw(10) << articleAchetee.nbre
			<< setw(20) << articleAchetee.article.prix
			<< setw(20) << articleAchetee.prixTotal 
			<< endl;
	}
}

int main() {
	// code...
	vector<Article> articles;
	vector<ArticleAchetee> panier;
	int nbArticles;
	int codeArticle;
	int quantiteArticle;
	float prixTotal;
	Article article;
	ArticleAchetee articleAchetee;

	initArticles(articles);

	cout << "Combien d’articles à facturer ? ";
	cin >> nbArticles;

	for (int i = 0; i < nbArticles; i++) {
		cout << "Code article ? ";

		do {
			cin  >> codeArticle;
			article = getArticle(articles, codeArticle);

			if (article.libelle == "") {
				cout << "** Article inexistant – redonnez le code : ";
			}
		}while (article.libelle == "");

		cout << "Quantité de " << article.libelle << " au prix unitaire de 3 700.00 ? ";
		cin >> quantiteArticle;


		// article achetée
		articleAchetee.article = article;
		articleAchetee.nbre = quantiteArticle;
		articleAchetee.prixTotal = article.prix * quantiteArticle;

		// enregistrement de l'article dans le panier		
		panier.push_back(articleAchetee);
	}


	afficherFacture(panier);
	
	return 0;
}