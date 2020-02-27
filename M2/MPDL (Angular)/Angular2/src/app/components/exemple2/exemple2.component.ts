import { Component, OnInit } from '@angular/core';
import { Observable, fromEvent } from 'rxjs';

@Component({
  selector: 'app-exemple2',
  templateUrl: './exemple2.component.html',
  styleUrls: ['./exemple2.component.scss'] 
})
export class Exemple2Component implements OnInit {

  data: Array<any> = [];

  $observable: Observable<any>;

  hover = 0;

  constructor() {
    this.$observable = fromEvent(document, 'click');
    this.$observable.subscribe(
      event => {
        console.log(event);
        this.data.push(event);
      }
    );

  }

  ngOnInit() {
    const elt = document.getElementById('myHeader');
    const obs = fromEvent(elt, 'mouseenter');
    obs.subscribe(
      s => this.hover++
    );
  }

}
