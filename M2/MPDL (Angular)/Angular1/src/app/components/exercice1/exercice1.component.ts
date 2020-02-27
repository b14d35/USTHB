import { Component, OnInit } from '@angular/core';

import { Tableau } from './../../model/tableau.model';

@Component({
  selector: 'app-exercice1',
  templateUrl: './exercice1.component.html',
  styleUrls: ['./exercice1.component.css']
})
export class Exercice1Component implements OnInit {
  tableau: Tableau;
  lastVal: number;
  show = 0;
  constructor() { }

  ngOnInit() {
    this.tableau = new Tableau();
    this.lastVal = 0;
  }

  afficher() {
    this.show = 1;
  }
}
