#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//Regions

int main()
{
	cout << "EXERCICIO 01 - REGIONS" << endl << endl;
	
	Mat imagem;
	Vec3b val;
	imagem = imread("biel.png", CV_LOAD_IMAGE_GRAYSCALE);
	if (!imagem.data) {
		cout << ("Nao abriu arquivo") << endl;
	}
	else {
		int P1x, P1y, P2x, P2y;
		int altura = imagem.size().height;
		int largura = imagem.size().width;
		cout << "A imagem tem altura " << altura << " e largura " << largura << endl << endl;
		cout << "Digite um ponto P1." << endl;
		while (1) {
			cout << "Coordenada X: ";
			cin >> P1x;
			if (P1x > 0 && P1x < largura) {
				break;
			}else {
				cout << "O Valor deve estar entre 1 e " << largura << endl;
			}
		}
		while (1) {
			cout << "Coordenada Y: ";
			cin >> P1y;
			if (P1y > 0 && P1y < altura) {
				break;
			}
			else {
				cout << "O Valor deve estar entre 1 e " << altura << endl;
			}
		}
		cout << endl << "Digite um ponto P2." << endl;
		while (1) {
			cout << "Coordenada X: ";
			cin >> P2x;
			if (P2x > 0 && P2x < largura) {
				break;
			}
			else {
				cout << "O Valor deve estar entre 1 e " << largura << endl;
			}
		}
		while (1) {
			cout << "Coordenada Y: ";
			cin >> P2y;
			if (P2y > 0 && P2y < altura) {
				break;
			}
			else {
				cout << "O Valor deve estar entre 1 e " << altura << endl;
			}
		}
		imshow("janela (Original)", imagem);

		waitKey();

		//Negativo de uma imagem eh: 255 - valor de cor do pixel.
		for (int i = P1x; i < P2x ; i++) {
			for (int j = P1y ;j < P2y ;j++) {
				imagem.at<uchar>(i, j) = 255 - imagem.at<uchar>(i, j);
			}
		}
		imshow("janela (Modificada)", imagem);
	}
	waitKey();
	return 0;
}