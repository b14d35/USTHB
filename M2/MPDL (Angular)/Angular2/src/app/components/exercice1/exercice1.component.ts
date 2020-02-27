import { Component, OnInit } from '@angular/core';
import { interval, Observable } from 'rxjs';
import { error } from 'protractor';

@Component({
  selector: 'app-exercice1',
  templateUrl: './exercice1.component.html',
  styleUrls: ['./exercice1.component.scss']
})
export class Exercice1Component implements OnInit {
  heure: number;
  minute: number;
  second: number;
  heureDeg: number;
  minuteDeg: number;
  secondDeg: number;
  obs: Observable<number>;



  getTime() {
    const date = new Date();
    this.heure = date.getHours();
    this.minute = date.getMinutes();
    this.second = date.getSeconds();
  }

  getDegres() {
    this.secondDeg = this.second * 6;
    this.minuteDeg = this.minute * 6;
    this.heureDeg = this.heure * 30 + (this.minute / 2);
  }

  initialiser() {
    this.getTime();
    this.getDegres();
  }

  ngOnInit() {
    this.initialiser();
    this.obs = interval(1000);
    this.obs.subscribe(
      s => {
        this.initialiser();
      }
    );
  }
}


