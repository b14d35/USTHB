import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { Example6Component } from './example6.component';

describe('Example6Component', () => {
  let component: Example6Component;
  let fixture: ComponentFixture<Example6Component>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ Example6Component ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(Example6Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
