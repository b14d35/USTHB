import { Component, OnInit, Input } from '@angular/core';
import { Training } from '/app/model/training';


@Component({
  selector: 'app-list-data',
  templateUrl: './list-data.component.html',
  styleUrls: ['./list-data.component.scss'],
  providers: []
})
export class ListDataComponent implements OnInit {

  @Input() trainings: Training[] = [];


  constructor() { }

  ngOnInit() {

  }

}
