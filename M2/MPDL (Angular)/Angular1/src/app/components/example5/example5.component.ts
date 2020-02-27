import { Component, OnInit } from '@angular/core';
import { Worker } from './../../model/worker';
import { Manager } from 'src/app/model/manager';

@Component({
  selector: 'app-example5',
  templateUrl: './example5.component.html',
  styleUrls: ['./example5.component.scss']
})
export class Example5Component implements OnInit {

  emp1: Worker;

  emp2: Worker;

  salary1: number;

  salary2 = 0;

  constructor() {
    this.emp1 = new Worker('Amine', 'Mostefai', 4000);
    this.emp2 = new Manager('Mohamed', 'Ahmed-Nacer', 6000, 100000);
    this.salary1 = this.emp1.getSalary();
    this.salary2 = this.emp2.getSalary();
  }

  ngOnInit() {
  }

}
