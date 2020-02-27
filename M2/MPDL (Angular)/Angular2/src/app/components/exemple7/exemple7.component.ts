import { Component, OnInit } from '@angular/core';
import { CountryService } from '/app/services/country/country.service';
import { finalize } from 'rxjs/operators';

@Component({
  selector: 'app-exemple7',
  templateUrl: './exemple7.component.html',
  styleUrls: ['./exemple7.component.scss']
})
export class Exemple7Component implements OnInit {
  error = false;

  loading = false;

  data: any;

  constructor(private $ser: CountryService) { }

  ngOnInit() {
  }

  getData() {
    const observable = this.$ser.getData().pipe(
      finalize(() => this.loading = false)
    );
    this.loading = true;
    observable.subscribe(
      s => this.data = s,
      error => this.error = true
    );
  }

}
