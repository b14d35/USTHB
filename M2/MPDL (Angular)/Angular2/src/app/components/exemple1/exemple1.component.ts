import { Component, OnInit } from '@angular/core';
import { Observable, Observer } from 'rxjs';

@Component({
  selector: 'app-exemple1',
  templateUrl: './exemple1.component.html',
  styleUrls: ['./exemple1.component.scss']
})
export class Exemple1Component implements OnInit {

  data: Array<any> = [];

  i = 0;

  $observable: Observable<string>;

  private $observer: Observer<string>;



  constructor() {
    this.$observable = new Observable(obs => {
      this.data.push(`Hello ${this.i++}`);
      console.log('C est bon, vous avez un observer !');
      this.$observer = obs;
    });
  }

  changed(val: string) {
    if (this.$observer) {
      this.$observer.next(val);
    }
  }

  click() {
    this.$observable.subscribe(
      s => this.data.push(s)
    );
  }

  ngOnInit() {
  }

}
