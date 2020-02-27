import { Component, OnInit } from '@angular/core';
import { AdvancedCountryService } from '/app/services/country/advanced-country.service';
import { finalize } from 'rxjs/operators';

@Component({
  selector: 'app-exemple8',
  templateUrl: './exemple8.component.html',
  styleUrls: ['./exemple8.component.scss']
})
export class Exemple8Component implements OnInit {

  error = false;

  loading = false;

  data: any;

  constructor(private $ser: AdvancedCountryService) { }

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
