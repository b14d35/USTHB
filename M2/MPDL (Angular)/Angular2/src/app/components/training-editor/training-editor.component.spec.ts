import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { TrainingEditorComponent } from './training-editor.component';

describe('TrainingEditorComponent', () => {
  let component: TrainingEditorComponent;
  let fixture: ComponentFixture<TrainingEditorComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ TrainingEditorComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(TrainingEditorComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
