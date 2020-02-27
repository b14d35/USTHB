import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { Exemple8Component } from './exemple8.component';

describe('Exemple8Component', () => {
  let component: Exemple8Component;
  let fixture: ComponentFixture<Exemple8Component>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ Exemple8Component ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(Exemple8Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
