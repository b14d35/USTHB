import { Component, OnInit, Input } from '@angular/core';
import { Observable, of } from 'rxjs';

@Component({
  selector: 'app-list',
  templateUrl: './list.component.html',
  styleUrls: ['./list.component.scss']
})
export class ListComponent implements OnInit {

  data: Array<any> = [];

  @Input() label: string;


  /** data */
  @Input() obs: Observable<any>;

  constructor() {

  }

  ngOnInit() {
    this.obs.subscribe(s => this.data.push(s));
  }

}
