import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  currentExample = 0;

  setExample(value: number) {
    this.currentExample = value;
  }

}
