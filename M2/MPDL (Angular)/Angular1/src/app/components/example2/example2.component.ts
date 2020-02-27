import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-example2',
  templateUrl: './example2.component.html',
  styleUrls: ['./example2.component.scss']
})
export class Example2Component implements OnInit {

  result1: number;
  result2: boolean;
  result3: string;
  result4: string;

  constructor() {

  }

  calc() {
    this.result1 = 11 + 26;
    this.result2 = this.result1 > 44;
    this.result3 = 'bonjour ' + 'tout le monde';
    this.result4 = `C'est cool ${this.result1} de code en TS`;

  }

  ngOnInit() {
  }

}
