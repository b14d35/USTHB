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

void enregistrer(file head, file tail, int S[4]) {
	FILE *F, *A;
	int x;
	A = fopen("Txt/Secret.txt", "w");
	fprintf(A, "%d\n%d\n%d\n%d\n", S[0], S[1], S[2], S[3]);
	fclose(A);
	F = fopen("Txt/Saved.txt", "w");
	while (head != NULL) {
		head = defiler(head, &tail, &x);
		fprintf(F, "%d ", x);
	}
	fclose(F);
}

void random(int Tableau[4]) {
	int i;
	srand(time(NULL));
	for (i = 0; i < 4; i++) {
		Tableau[i] = (rand() % 6) + 1;
	}
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

void playing(SDL_Surface *screen) {
	int S[4], V[4], T[4], i = 0, j, cn = 1, cn1, pl, pl1, y, t;
	char c[20];
	FILE *A;
	SDL_Surface *imgbg = NULL, *img = NULL, *img1 = NULL, *text = NULL;
	SDL_Event ev;
	SDL_Rect posimg, posimgbg, posimg1, pos, pos2;
	TTF_Font *plc = NULL;
	file head = NULL, tail = NULL;
	TTF_Init();
	random(S);
	pos2.x = 40;
	pos2.y = 90;
	pos.x = 100;
	pos.y = 100;
	imgbg = IMG_Load("Pics/PlayP.jpg");
	posimgbg.x = 0;
	posimgbg.y = 0;
	posimg.y = 627;
	posimg1.y = 640;
	SDL_BlitSurface(imgbg, NULL, screen, &posimgbg);
	SDL_Flip(screen);
	while (i < 10 && cn && pl) {
		posimg.x = 140;
		posimg1.x = 500;
		j = 0;
		while (j < 4 && cn) {
			cn1 = 1;
			while (cn1) {
				SDL_WaitEvent(&ev);
				switch (ev.type) {
					case SDL_QUIT:
						cn = 0;
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
								V[j] = y;
								tail = enfiler(&head, tail, y);
								img = IMG_Load(c);
								SDL_SetColorKey(
									img, SDL_SRCCOLORKEY,
									SDL_MapRGB(img->format, 255, 255, 255));
								SDL_BlitSurface(img, NULL, imgbg, &posimg);
								SDL_BlitSurface(imgbg, NULL, screen, &posimgbg);
								cn1 = 0;
								break;
							case SDLK_s:
								enregistrer(head, tail, S);
								return;
								break;
							case SDLK_x:
								return;
								break;
						}
						break;
					}
				}
			}
			SDL_Flip(screen);
			posimg.x = posimg.x + 90;
			j++;
		}
		cn1 = 1;
		while (cn1 && cn) {
			SDL_WaitEvent(&ev);
			switch (ev.type) {
				case SDL_KEYDOWN: {
					cn1 = 0;
					if (winner(S, V) == 1) {
						pl = 0;
						img1 = IMG_Load("Pics/YOUWIN.png");
						SDL_FillRect(screen, NULL,
									 SDL_MapRGB(screen->format, 0, 0, 0));
						SDL_BlitSurface(img1, NULL, screen, &pos);
						SDL_Flip(screen);
						SDL_Delay(3000);
						best_score(i);
					} else {
						for (t = 0; t < 4; t++) {
							if (V[t] == S[t]) {
								T[t] = S[t];
							} else {
								T[t] = 0;
							}
						}
						int noire = 0, blan = 0, k;
						for (y = 0; y < 4; y++) {
							if (V[y] == S[y]) {
								noire++;
							} else {
								pl1 = 1;
								k = 0;
								while (k < 4 && pl) {
									if (k != y && pl1 == 1) {
										if (V[y] == S[k] && T[k] != S[k]) {
											blan++;
											pl1 = 0;
										}
									}
									k++;
								}
							}
						}
						posimg1.x = posimg1.x + 35;
						posimg1.y = posimg1.y - 15;
						k = noire + blan;
						for (y = 0; y < k; y++) {
							if (y < noire) {
								strcpy(c, "Balls/BLACK.png");
							} else {
								strcpy(c, "Balls/WHITE.png");
							}
							img1 = IMG_Load(c);
							SDL_SetColorKey(
								img1, SDL_SRCCOLORKEY,
								SDL_MapRGB(img1->format, 255, 255, 255));
							SDL_BlitSurface(img1, NULL, imgbg, &posimg1);
							SDL_BlitSurface(imgbg, NULL, screen, &posimgbg);
							SDL_Flip(screen);
							posimg1.x = posimg1.x + 70;
						}
					}
					posimg.y = posimg.y - 56;
					posimg1.y = posimg1.y - 41;
					i++;
				} break;
			}
		}
	}
	if (pl) {
		img1 = IMG_Load("Pics/YOULOSE.png");
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(img1, NULL, screen, &pos);
		SDL_Flip(screen);
		SDL_Delay(3000);
	}
	SDL_FreeSurface(img);
	SDL_FreeSurface(img1);
	SDL_FreeSurface(text);
	TTF_CloseFont(plc);
	TTF_Quit();
}

void replay(SDL_Surface *screen) {
	int S[4], V[4], T[4], i = 1, j, cn = 1, cn1, pl, pl1, y, k = 0, x, t;
	char c[20];
	FILE *A, *B;
	SDL_Surface *imgbg = NULL, *img = NULL, *img1 = NULL, *text = NULL;
	SDL_Event ev;
	SDL_Rect posimg, posimgbg, posimg1, pos, pos2;
	TTF_Font *plc = NULL;
	file head = NULL, tail = NULL;
	TTF_Init();
	A = fopen("Txt/Saved.txt", "r");
	B = fopen("Txt/Secret.txt", "r");
	while (!feof(B)) {
		fscanf(B, "%d\n", &S[k]);
		k++;
	}
	fclose(B);
	pos2.x = 40;
	pos2.y = 90;
	pos.x = 100;
	pos.y = 100;
	imgbg = IMG_Load("Pics/PlayP.jpg");
	posimgbg.x = 0;
	posimgbg.y = 0;
	posimg.y = 627;
	posimg1.y = 640;
	SDL_BlitSurface(imgbg, NULL, screen, &posimgbg);
	SDL_Flip(screen);
	while (i <= 10 && !feof(A)) {
		posimg.x = 140;
		posimg1.x = 500;
		j = 0;
		while (j < 4 && !feof(A)) {
			fscanf(A, "%d ", &x);
			switch (x) {
				case 1:
					strcpy(c, "Balls/RED.png");
					break;
				case 2:
					strcpy(c, "Balls/BLUE.png");
					break;
				case 3:
					strcpy(c, "Balls/YELLOW.png");
					break;
				case 4:
					strcpy(c, "Balls/ORENGE.png");
					break;
				case 5:
					strcpy(c, "Balls/GREEN.png");
					break;
				case 6:
					strcpy(c, "Balls/PERPEL.png");
					break;
			}
			V[j] = x;
			tail = enfiler(&head, tail, x);
			img = IMG_Load(c);
			SDL_SetColorKey(img, SDL_SRCCOLORKEY,
							SDL_MapRGB(img->format, 255, 255, 255));
			SDL_BlitSurface(img, NULL, imgbg, &posimg);
			SDL_BlitSurface(imgbg, NULL, screen, &posimgbg);
			SDL_Flip(screen);
			posimg.x = posimg.x + 90;
			j++;
		}
		if (j == 4) {
			for (t = 0; t < 4; t++) {
				if (V[t] == S[t]) {
					T[t] = S[t];
				} else {
					T[t] = 0;
				}
			}
			int noire = 0, blan = 0;
			for (y = 0; y < 4; y++) {
				if (V[y] == S[y]) {
					noire++;
				} else {
					pl1 = 1;
					k = 0;
					while (k < 4 && pl1) {
						if (k != y) {
							if (V[y] == S[k] && T[k] != S[k]) {
								blan++;
								pl1 = 0;
							}
						}
						k++;
					}
				}
			}
			posimg1.x = posimg1.x + 35;
			posimg1.y = posimg1.y - 15;
			k = noire + blan;
			for (y = 0; y < k; y++) {
				if (y < noire) {
					strcpy(c, "Balls/BLACK.png");
				} else {
					strcpy(c, "Balls/WHITE.png");
				}
				img1 = IMG_Load(c);
				SDL_SetColorKey(img1, SDL_SRCCOLORKEY,
								SDL_MapRGB(img1->format, 255, 255, 255));
				SDL_BlitSurface(img1, NULL, imgbg, &posimg1);
				SDL_BlitSurface(imgbg, NULL, screen, &posimgbg);
				SDL_Flip(screen);
				posimg1.x = posimg1.x + 70;
			}
		}
		posimg.y = posimg.y - 56;
		posimg1.y = posimg1.y - 41;
		i++;
	}
	fclose(A);
	i--;
	posimg.y = posimg.y + 53;
	posimg1.y = posimg.y + 49;
	if (j == 4) {
		j = 0;
		i++;
		posimg.x = 140;
		posimg1.x = 500;
		posimg1.y = posimg.y - 43;
		posimg.y = posimg.y - 56;
	}
	while (i <= 10 && pl && cn) {
		while (j < 4 && cn) {
			cn1 = 1;
			while (cn1) {
				SDL_WaitEvent(&ev);
				switch (ev.type) {
					case SDL_QUIT:
						cn = 0;
						cn1 = 0;
						break;
					case SDL_KEYDOWN: {
						switch (ev.key.keysym.sym) {
							case SDLK_r:
								y = 1;
								strcpy(c, "Balls/RED.png");
								goto here;
							case SDLK_b:
								y = 2;
								strcpy(c, "Balls/BLUE.png");
								goto here;
							case SDLK_y:
								y = 3;
								strcpy(c, "Balls/YELLOW.png");
								goto here;
							case SDLK_o:
								y = 4;
								strcpy(c, "Balls/ORENGE.png");
								goto here;
							case SDLK_g:
								y = 5;
								strcpy(c, "Balls/GREEN.png");
								goto here;
							case SDLK_p:
								y = 6;
								strcpy(c, "Balls/PERPEL.png");
							here:
								V[j] = y;
								tail = enfiler(&head, tail, y);
								img = IMG_Load(c);
								SDL_SetColorKey(
									img, SDL_SRCCOLORKEY,
									SDL_MapRGB(img->format, 255, 255, 255));
								SDL_BlitSurface(img, NULL, imgbg, &posimg);
								SDL_BlitSurface(imgbg, NULL, screen, &posimgbg);
								cn1 = 0;
								break;
							case SDLK_s:
								enregistrer(head, tail, S);
								return;
								break;
							case SDLK_x:
								return;
								break;
						}
						break;
					}
				}
			}
			SDL_Flip(screen);
			posimg.x = posimg.x + 90;
			j++;
		}
		cn1 = 1;
		while (cn1 && cn) {
			SDL_WaitEvent(&ev);
			switch (ev.type) {
				case SDL_KEYDOWN: {
					cn1 = 0;
					if (winner(S, V) == 1) {
						pl = 0;
						img1 = IMG_Load("Pics/YOUWIN.png");
						SDL_FillRect(screen, NULL,
									 SDL_MapRGB(screen->format, 0, 0, 0));
						SDL_BlitSurface(img1, NULL, screen, &pos);
						SDL_Flip(screen);
						SDL_Delay(3000);
						best_score(i);
					} else {
						for (t = 0; t < 4; t++) {
							if (V[t] == S[t]) {
								T[t] = S[t];
							} else {
								T[t] = 0;
							}
						}
						int noire = 0, blan = 0, k;
						for (y = 0; y < 4; y++) {
							if (V[y] == S[y]) {
								noire++;
							} else {
								pl1 = 1;
								k = 0;
								while (k < 4 && pl1) {
									if (k != y) {
										if (V[y] == S[k] && T[k] != S[k]) {
											blan++;
											pl1 = 0;
										}
									}
									k++;
								}
							}
						}
						posimg1.x = posimg1.x + 35;
						posimg1.y = posimg1.y - 15;
						k = noire + blan;
						for (y = 0; y < k; y++) {
							if (y < noire) {
								strcpy(c, "Balls/BLACK.png");
							} else {
								strcpy(c, "Balls/WHITE.png");
							}
							img1 = IMG_Load(c);
							SDL_SetColorKey(
								img1, SDL_SRCCOLORKEY,
								SDL_MapRGB(img1->format, 255, 255, 255));
							SDL_BlitSurface(img1, NULL, imgbg, &posimg1);
							SDL_BlitSurface(imgbg, NULL, screen, &posimgbg);
							SDL_Flip(screen);
							posimg1.x = posimg1.x + 70;
						}
					}
					posimg.y = posimg.y - 54l;
					posimg1.y = posimg1.y - 40;
					i++;
				} break;
			}
		}
		posimg.x = 140;
		posimg1.x = 500;
		j = 0;
	}
	if (pl) {
		img1 = IMG_Load("Pics/YOULOSE.png");
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(img1, NULL, screen, &pos);
		SDL_Flip(screen);
		SDL_Delay(3000);
	}
	SDL_FreeSurface(img);
	SDL_FreeSurface(img1);
	SDL_FreeSurface(text);
	TTF_CloseFont(plc);
	TTF_Quit();
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
	img = IMG_Load("Pics/MenuP.jpg");
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
					case SDLK_l:
						replay(screen);
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
