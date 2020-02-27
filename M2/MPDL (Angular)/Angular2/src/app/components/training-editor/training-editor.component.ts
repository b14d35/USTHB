import { Component, OnInit } from '@angular/core';
import { Training } from '/app/model/training';
import { TrainingService } from '/app/services/training/training.service';

@Component({
  selector: 'app-training-editor',
  templateUrl: './training-editor.component.html',
  styleUrls: ['./training-editor.component.scss']
})
export class TrainingEditorComponent implements OnInit {

  evaluation : number;

  title: string;

  domain: string;

  constructor(private $service: TrainingService) { }

  add() {
    const t: Training = {
      title: this.title,
      domain: this.domain,
      evaluation : this.evaluation
    };
    this.$service.addTraining(t);
  }

  ngOnInit() {
  }

}
