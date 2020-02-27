import { Component, OnInit, OnDestroy } from '@angular/core';
import { SearchService } from '/app/services/movie/search.service';
import { interval, Observable, Subscription } from 'rxjs';
import { DomSanitizer } from '@angular/platform-browser';
import { error } from 'protractor';
import { Search } from '/app/model/search';
import { Movie } from '/app/model/movie';
@Component({
  selector: 'app-exercice2',
  templateUrl: './exercice2.component.html',
  styleUrls: ['./exercice2.component.scss']
})
export class Exercice2Component implements OnInit, OnDestroy {
  show: number;
  // Search variables
  query: string;
  year: number;
  language: string;
  page: number;
  // Result search variables
  resultSearch: any;
  resultSearchLatest: any;
  // Slide variables
  currentSlide: number;
  maxSlide: number;
  obsSlide: Observable<number>;
  obsSlideLatest: Observable<number>;
  subs: Subscription;
  subsLatest: Subscription;
  // Images
  noImage = 'https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQ-HTI1S2w4KbwpeOY9upP1BWcZ0Oc-SQ4vfJb6JIv4jX9VbO-G';
  // Movie
  subsMovie: Subscription;
  mov: Movie;
  showMovie: number;
  constructor(private $ser: SearchService, public sanitizer: DomSanitizer) {

  }

  searchLatest() {
    this.$ser.GetDataLatest().subscribe(
      s => {
        this.resultSearchLatest = s;
        const sizeResult = this.resultSearchLatest.results.length;
        this.maxSlide = sizeResult;
        this.obsSlideLatest = interval(3000);
        this.subsLatest = this.obsSlideLatest.subscribe(
          t => {
            this.currentSlide = (this.currentSlide + 1) % this.maxSlide;
          }
        );
      }
    );
  }

  search(page: number) {
    this.showMovie = 0;
    if (this.obsSlideLatest !== undefined) {
      this.subsLatest.unsubscribe();
    }
    if (this.obsSlide !== undefined) {
      this.subs.unsubscribe();
    }
    this.page = page;
    this.currentSlide = 0;
    if (this.query !== '') {
      // Todo: I have a problem of undifined at the first search
      this.$ser.GetData(this.query, this.year, this.language, this.page).subscribe(
        s => {
          this.resultSearch = s;
          const sizeResult = this.resultSearch.results.length;
          this.show = (sizeResult > 0) ? 1 : 0;
          this.maxSlide = (sizeResult > 8) ? 8 : sizeResult;
          this.obsSlide = interval(3000);
          this.subs = this.obsSlide.subscribe(
            t => {
              this.currentSlide = (this.currentSlide + 1) % this.maxSlide;
            }
          );
        }
      );
    }
  }

  movie(id: number) {
    this.subsMovie = this.$ser.GetMovie(id, this.language).subscribe(
      s => {
        this.mov = s;
        this.showMovie = id;
      }
    );
  }

  hideMovie() {
    this.showMovie = 0;
  }

  getStars(avg: number) {
    let arr = [];
    for (let i = 1; i <= avg; i++) {
      arr.push(0);
    }
    return arr;
  }

  ngOnInit() {
    this.show = 0;
    this.currentSlide = 0;
    this.maxSlide = 0;
    this.query = '';
    this.showMovie = 0;
    this.language = 'en';
    // this doesn't seem to work on direct call
    this.searchLatest();
  }

  ngOnDestroy() {
    this.subs.unsubscribe();
    this.subsMovie.unsubscribe();
  }
}
