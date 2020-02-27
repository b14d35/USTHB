import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { Exemple3Component } from './exemple3.component';

describe('Exemple3Component', () => {
  let component: Exemple3Component;
  let fixture: ComponentFixture<Exemple3Component>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ Exemple3Component ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(Exemple3Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
