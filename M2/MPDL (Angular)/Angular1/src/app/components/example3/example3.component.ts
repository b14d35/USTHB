import { Component, OnInit } from '@angular/core';

/** fonction avec paramètres et type de retour */
function fun1(p1: number, p2: number): number {
  return p1 * p2;
}

/** fonction avec paramètre optionnel */
function fun2(p1: number, p2?: number) {
  return p1 * p2;
}

/** fonction avec paramètre optionnel et valeur par défaut */
function fun3(p1: number, p2?: number) {
  p2 = p2 || 5;
  return p1 * p2;
}

/** fonction avec expression lambda */
const fun4 = (p1: number, p2: number) => p1 + p2;


@Component({
  selector: 'app-example3',
  templateUrl: './example3.component.html',
  styleUrls: ['./example3.component.scss']
})
export class Example3Component implements OnInit {

  result1: number;
  result2: number;
  result3: number;
  result4: number;


  constructor() { }

  calc() {
    this.result1 = fun1(14, 7);
    this.result2 = fun2(11);
    this.result3 = fun3(11);
    this.result3 = fun3(11);
    this.result4 = fun3(11, 47);
  }

  ngOnInit() {
  }

}
