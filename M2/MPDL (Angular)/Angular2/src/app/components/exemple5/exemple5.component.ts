import { Component, OnInit } from '@angular/core';
import { Training } from '/app/model/training';
import { TrainingService } from '/app/services/training/training.service';

@Component({
  selector: 'app-exemple5',
  templateUrl: './exemple5.component.html',
  styleUrls: ['./exemple5.component.scss']
})
export class Exemple5Component implements OnInit {

  data: Training[];

  constructor(private $ser: TrainingService) {
    $ser.getList().subscribe(s => this.data = s);
  } 

  ngOnInit() {
  }

}
