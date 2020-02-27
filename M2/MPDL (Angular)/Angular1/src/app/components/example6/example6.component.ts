import { Component, OnInit } from '@angular/core';
import { Resource } from './../../model/resource';
import { Worker } from './../../model/worker';
import { Energy } from 'src/app/model/energy';

@Component({
  selector: 'app-example6',
  templateUrl: './example6.component.html',
  styleUrls: ['./example6.component.scss']
})
export class Example6Component implements OnInit {

  cost1: number;

  cost2: number;

  cost3: number;



  calcCost(r: Resource): number {
    return r.getCost(25);
  }

  constructor() { }

  ngOnInit() {
    const equipment: Resource = {
      name: 'equipment',
      getCost: d => 4500 * d
    };
    this.cost1 = this.calcCost(equipment);
    const worker = new Worker('amine', 'mostefai', 400);
    this.cost2 = this.calcCost(worker);
    const el = new Energy();
    el.name = 'electricity';
    this.cost3 = this.calcCost(el);
  }

}
