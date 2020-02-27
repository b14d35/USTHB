import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Observable, of } from 'rxjs';
import { Injectable } from '@angular/core';
import { tap } from 'rxjs/operators';

@Injectable({
    providedIn: 'root'
})
export class AdvancedCountryService {

    private $cache = undefined;

    constructor(private $http: HttpClient) {

    }

    getData(): Observable<any> {
        if (this.$cache) {
            console.log('Getting data from cache');
            return of(this.$cache);
        }
        console.log('Getting data from server');
        let headers = new HttpHeaders();
        headers = headers.append('x-rapidapi-host', 'restcountries-v1.p.rapidapi.com');
        headers = headers.append('x-rapidapi-key', 'd8b69ce868mshe1883fd24db3134p143b34jsn40307eef82ad');
        return this.$http.get('https://restcountries-v1.p.rapidapi.com/all', { headers }).pipe(
            tap(success => this.$cache = success)
        );
    }
}
