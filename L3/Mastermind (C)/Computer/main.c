#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct noeud *file;
typedef struct noeud {
	int info;
	file svt;
} noeud;

int winner(int A[4], int B[4]) {
	int i;
	for (i = 0; i < 4; i++) {
		if (A[i] != B[i]) {
			return 0;
		}
	}
	return 1;
}

file enfiler(file *A, file B, int x) {
	file C;
	C = malloc(sizeof(noeud));
	C->info = x;
	if (*A == NULL) {
		C->svt = NULL;
		*A = C;
	} else {
		C->svt = B->svt;
		B->svt = C;
	}
	B = C;
	return B;
}

file defiler(file A, file *B, int *x) {
	file C;
	if (A != NULL) {
		C = A;
		*x = A->info;
		A = A->svt;
		free(C);
		if (A == NULL) *B = NULL;
	}
	return A;
}

void best_score(int x) {
	FILE *A, *B;
	int y, c = 1;
	A = fopen("Txt/Temp.txt", "w");
	B = fopen("Txt/HighScores.txt", "r");
	while (!feof(B)) {
		fscanf(B, "%d\n", &y);
		if (x < y) {
			fprintf(A, "%d\n", x);
		}
		fprintf(A, "%d\n", y);
	}
	fclose(A);
	fclose(B);
	remove("Txt/HighScores.txt");
	rename("Txt/Temp.txt", "Txt/HighScores.txt");
}

void afficher_best_score(SDL_Surface *screen) {
	int x;
	FILE *A;
	char c[20];
	SDL_Surface *text = NULL, *bg = NULL;
	SDL_Rect pos;
	SDL_Event ev;
	SDL_Color CN = {255, 255, 255};
	TTF_Init();
	TTF_Font *plc = NULL;
	plc = TTF_OpenFont("Pics/angelina.TTF", 70);
	TTF_SetFontStyle(plc, TTF_STYLE_ITALIC);
	bg = IMG_Load("Pics/PLAY.jpg");
	text = TTF_RenderText_Blended(plc, "High Scores :", CN);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	pos.x = 0;
	pos.y = 30;
	SDL_BlitSurface(text, NULL, screen, &pos);
	SDL_Flip(screen);
	pos.y = 80;
	A = fopen("Txt/HighScores.txt", "r");
	while (!feof(A)) {
		fscanf(A, "%d\n", &x);
		sprintf(c, "%d", x);
		text = TTF_RenderText_Blended(plc, c, CN);
		SDL_BlitSurface(text, NULL, screen, &pos);
		SDL_Flip(screen);
		pos.y = pos.y + 50;
	}
	while (1) {
		SDL_WaitEvent(&screen);
		if (ev.type == SDL_QUIT) break;
	}
	SDL_FreeSurface(text);
	TTF_CloseFont(plc);
	TTF_Quit();
}

void playing(SDL_Surface *ecran) {
	int S[4], V[4], T[4], Tb[4], i = 0, j = 0, cn = 1, cn1, pl, pl1, y, t, z;
	int noire, blan, k;
	char c[20];
	FILE *A;
	SDL_Surface *imagefond = NULL, *image = NULL, *image1 = NULL, *texte = NULL;
	SDL_Event ev;
	SDL_Rect posimg, posimgbg, posimg1, pos, pos2;
	TTF_Font *plc = NULL;
	file head = NULL, tail = NULL;
	pos2.x = 40;
	pos2.y = 90;
	posimg.x = 60;
	posimg.y = 57;
	pos.x = 0;
	pos.y = 30;
	imagefond = IMG_Load("Pics/PlayC.jpg");
	posimgbg.x = 0;
	posimgbg.y = 0;
	posimg1.x = 560;
	posimg1.y = 630;
	SDL_Color CN = {0, 0, 0};
	SDL_BlitSurface(imagefond, NULL, ecran, &posimgbg);
	SDL_Flip(ecran);
	while (j <= 3) {
		cn1 = 1;
		while (cn1) {
			SDL_WaitEvent(&ev);
			switch (ev.type) {
				case SDL_QUIT:
					cn1 = 0;
					break;
				case SDL_KEYDOWN: {
					switch (ev.key.keysym.sym) {
						case SDLK_r:
							y = 1;
							strcpy(c, "Balls/RED.png");
							goto ici;
						case SDLK_b:
							y = 2;
							strcpy(c, "Balls/BLUE.png");
							goto ici;
						case SDLK_y:
							y = 3;
							strcpy(c, "Balls/YELLOW.png");
							goto ici;
						case SDLK_o:
							y = 4;
							strcpy(c, "Balls/ORENGE.png");
							goto ici;
						case SDLK_g:
							y = 5;
							strcpy(c, "Balls/GREEN.png");
							goto ici;
						case SDLK_p:
							y = 6;
							strcpy(c, "Balls/PERPEL.png");
						ici:
							S[j] = y;
							image = IMG_Load(c);
							SDL_SetColorKey(
								image, SDL_SRCCOLORKEY,
								SDL_MapRGB(image->format, 255, 255, 255));
							SDL_BlitSurface(image, NULL, imagefond, &posimg);
							SDL_BlitSurface(imagefond, NULL, ecran, &posimgbg);
							cn1 = 0;
					}
					break;
				} break;
			}
		}
		SDL_Flip(ecran);
		posimg.x = posimg.x + 125;
		j++;
	}
	posimg.x = 60;
	posimg.y = 630;
	for (j = 0; j < 4; j++) {
		V[j] = 1;
		Tb[j] = 0;
	}
	do {
		for (j = 0; j < 4; j++) {
			switch (V[j]) {
				case 1:
					strcpy(c, "Balls/RED.png");
					goto here;
				case 2:
					strcpy(c, "Balls/BLUE.png");
					goto here;
				case 3:
					strcpy(c, "Balls/YELLOW.png");
					goto here;
				case 4:
					strcpy(c, "Balls/ORENGE.png");
					goto here;
				case 5:
					strcpy(c, "Balls/GREEN.png");
					goto here;
				case 6:
					strcpy(c, "Balls/PERPEL.png");
				here:
					image = IMG_Load(c);
					SDL_SetColorKey(image, SDL_SRCCOLORKEY,
									SDL_MapRGB(image->format, 255, 255, 255));
					SDL_BlitSurface(image, NULL, imagefond, &posimg);
					SDL_BlitSurface(imagefond, NULL, ecran, &posimgbg);
					SDL_Flip(ecran);
			}
			posimg.x = posimg.x + 125;
		}
		noire = 0;
		blan = 0;
		for (t = 0; t < 4; t++) {
			if (S[t] == V[t]) {
				T[t] = V[t];
			} else {
				T[t] = 0;
			}
		}
		for (y = 0; y < 4; y++) {
			if (S[y] == V[y]) {
				noire++;
				Tb[y] = S[y];
			} else {
				k = 0;
				while (k < 4) {
					if (k != y) {
						if (S[y] == V[k] && S[k] != T[k]) {
							blan++;
						}
					}
					k++;
				}
			}
		}
		for (y = 0; y < noire; y++) {
			image1 = IMG_Load("Balls/BLACK.png");
			SDL_SetColorKey(image1, SDL_SRCCOLORKEY,
							SDL_MapRGB(image1->format, 255, 255, 255));
			SDL_BlitSurface(image1, NULL, imagefond, &posimg1);
			SDL_BlitSurface(imagefond, NULL, ecran, &posimgbg);
			SDL_Flip(ecran);
			posimg1.x = posimg1.x + 70;
		}
		for (y = 0; y < blan; y++) {
			SDL_Flip(ecran);
			image1 = IMG_Load("Balls/WHITE.png");
			SDL_SetColorKey(image1, SDL_SRCCOLORKEY,
							SDL_MapRGB(image1->format, 255, 255, 255));
			SDL_BlitSurface(image1, NULL, imagefond, &posimg1);
			SDL_BlitSurface(imagefond, NULL, ecran, &posimgbg);
			SDL_Flip(ecran);
			posimg1.x = posimg1.x + 70;
		}
		SDL_Delay(3000);
		i++;
		for (j = 0; j < 4; j++) {
			if (Tb[j] == 0) {
				z = V[j];
				do {
					V[j] = (rand() % 6) + 1;
				} while (V[j] == z);
			}
		}
		posimg.x = 60;
		posimg.y = posimg.y - 56;
		posimg1.x = 560;
		posimg1.y = posimg1.y - 56;
	} while (i < 10 && winner(Tb, S) == 0);
	if (i == 10) {
		image1 = IMG_Load("Pics/YOULOSE.png");
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		SDL_BlitSurface(image1, NULL, ecran, &pos);
		SDL_Flip(ecran);
		SDL_Delay(3000);
	} else {
		best_score(i);
		image1 = IMG_Load("Pics/YOUWIN.png");
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		SDL_BlitSurface(image1, NULL, ecran, &pos);
		SDL_Flip(ecran);
		SDL_Delay(3000);
	}
	SDL_FreeSurface(image);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(texte);
}
int main(int argc, char *argv[]) {
	int cn = 1;
	SDL_Surface *screen = NULL, *img = NULL;
	SDL_Event ev;
	SDL_Rect posimg;
	posimg.x = 0;
	posimg.y = 50;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetIcon(SDL_LoadBMP("Pics/icon.bmp"), NULL);
	screen = SDL_SetVideoMode(900, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("M A S T E R M I N D", NULL);
	img = IMG_Load("Pics/MenuC.jpg");
	while (cn) {
		SDL_WaitEvent(&ev);
		switch (ev.type) {
			case SDL_QUIT:
				cn = 0;
				break;
			case SDL_KEYDOWN: {
				switch (ev.key.keysym.sym) {
					case SDLK_p:
						playing(screen);
						break;
					case SDLK_b:
						afficher_best_score(screen);
						break;
					case SDLK_x:
						return 0;
						break;
				}
			} break;
		}
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(img, NULL, screen, &posimg);
		SDL_Flip(screen);
	}
	SDL_FreeSurface(img);
	SDL_Quit();
	return 666;
}
