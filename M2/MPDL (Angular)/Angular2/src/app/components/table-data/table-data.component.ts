import { Component, OnInit, Input } from '@angular/core';
import { Training } from '/app/model/training';

@Component({
  selector: 'app-table-data',
  templateUrl: './table-data.component.html',
  styleUrls: ['./table-data.component.scss'],
  providers: []
})
export class TableDataComponent implements OnInit {

  @Input() trainings: Training[] = [];

  constructor() { }

  ngOnInit() {
  }

}
