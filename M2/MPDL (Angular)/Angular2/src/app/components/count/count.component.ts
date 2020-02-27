import { Component, OnInit } from '@angular/core';
import { TrainingService } from '/app/services/training/training.service';

@Component({
  selector: 'app-count',
  templateUrl: './count.component.html',
  styleUrls: ['./count.component.scss']
})
export class CountComponent implements OnInit {

  count = 0;

  constructor(private $ser: TrainingService) { }

  ngOnInit() {
    this.$ser.observable.subscribe(s => this.count = s.length);
  }

}
