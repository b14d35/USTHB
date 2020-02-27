import { Injectable } from '@angular/core';
import { Training } from '/app/model/training';
import { Observable, of, from, Observer, ReplaySubject } from 'rxjs';
import { share } from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})
export class TrainingService {

  private $observer: Observer<Training[]>;

  private $observable: Observable<Training[]>;

  private $subject: ReplaySubject<Training[]>;

  private $data: Training[] = [
    { domain: 'Frontend Dev', title: 'Angular', evaluation: 5, description: 'A cool training about Angular' },
    { domain: 'Frontend Dev', title: 'React', evaluation: 2, description: 'Just to tell why React is not for me' },
    { domain: 'Backend Dev', title: 'Django', evaluation: 2, description: 'Why the hell are you teaching this' },
    { domain: 'Backend Dev', title: '.NET Core', evaluation: 5, description: 'The best of the best !' },
  ];

  constructor() {
    this.$observable = new Observable<Training[]>(obs => {
      this.$observer = obs;
      this.$observer.next(this.$data);
    }).pipe(
      share()
    );
    this.$subject = new ReplaySubject<Training[]>();
    this.$subject.next(this.$data);
  }

  public addTraining(t: Training) {
    this.$data.push(t);
    if (this.$observer) {
      this.$observer.next(this.$data);
    }
    this.$subject.next(this.$data);
  }

  getData(): Observable<Training> {
    return from(this.$data);
  }

  getList(): Observable<Training[]> {
    return of(this.$data);
  }

  public get observable(): Observable<Training[]> {
    return this.$subject    ;
  }
}
