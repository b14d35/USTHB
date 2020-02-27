import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-example4',
  templateUrl: './example4.component.html',
  styleUrls: ['./example4.component.scss']
})
export class Example4Component implements OnInit {

  tab1 = [25, 46, 19, 58];

  tab2: Array<number> = [14, 89, 23, 15];

  tab3: Array<number>;

  tab4: Array<number>;

  tab5: Array<number> = [11, 77, 99, 8];

  tab6: Array<number>;


  constructor() { }

  ngOnInit() {
    this.tab3 = this.tab1.sort();
    this.tab4 = this.tab2.filter((v, i) => v > 20);
    this.tab5.splice(0, 2);
    this.tab6 = this.tab2.slice(1, 3);
  }

}
