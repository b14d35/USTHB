import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Search } from '/app/model/search';
import { Movie } from '/app/model/movie';

@Injectable({
  providedIn: 'root'
})
export class SearchService {
  private searchUrl = 'https://api.themoviedb.org/3/search/movie';
  private movieUrl = 'https://api.themoviedb.org/3/movie/';

  private apiKey = 'Your-API-Key-Here';

  constructor(private http: HttpClient) {
  }

  GetData(query: string, year: number, language: string, page: number): Observable<any> {
    const searchUrl = `${this.searchUrl}?api_key=${this.apiKey}&language=${language}&query=${query}&page=${page}&year=${year}`;
    return this.http.get(searchUrl);
  }

  GetMovie(id: number, language: string): Observable<Movie> {
    const movieUrl = `${this.movieUrl}${id}?api_key=${this.apiKey}&language=${language}&append_to_response=videos`;
    return this.http.get<Movie>(movieUrl);
  }

  GetDataLatest(): Observable<any> {
    const movieUrlUpcoming = `${this.movieUrl}upcoming?api_key=${this.apiKey}`;
    return this.http.get(movieUrlUpcoming);
  }

}
