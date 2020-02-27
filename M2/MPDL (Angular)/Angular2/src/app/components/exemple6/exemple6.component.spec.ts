import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { Exemple6Component } from './exemple6.component';

describe('Exemple6Component', () => {
  let component: Exemple6Component;
  let fixture: ComponentFixture<Exemple6Component>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ Exemple6Component ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(Exemple6Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
